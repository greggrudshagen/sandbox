/*
  I placed the spam.c file in ~/tmp and left my terminal at that directory.
  Create the Makefile and then to the make

  echo obj-m := spam.0 > Makefile
  make -C /lib/modules/'uname -r'/build M=$PWD modules


  load module by insmod spam.ko or may need sudo insmod spam.ko

  use lsmod | head -5 to see that the module is loaded

  remove module by rmmod spam.ko or may need sudo rmmod spam.ko
*/









#include <linux/init.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/string.h>


static char const * spam_strings[] = {
    "As seen on",
    "Buy direct",
    "Buying judgments",
    "Dig up dirt on friends",
    "Meet singles",
    "Score with babes",
    "Money making",
    "Online biz opportunity",
    "Online degree",
    "Potential earnings",
    "University diploma",
    "While you sleep",
    "Work at home",
    "Work from home",
    "Incredible deal",
    0 // End pointer
};


static struct nf_hook_ops nfho;

static unsigned int hook_func(const struct nf_hook_ops *ops,
                                   struct sk_buff *skb,
                                   const struct net_device *in,
                                   const struct net_device *out,
                                   int (*okfn)(struct sk_buff *))
{
    struct iphdr *iph;          /* IPv4 header */
    u32 saddr, daddr;           /* Source and destination addresses */
    unsigned char *pkt_data;    /* IP data begin pointer */
    unsigned char *tail;        /* IP data end pointer */
    unsigned char *it;          /* Data iterator */
    char const ** pSpamStrings; /* To the array of strings */    

    if (!skb)
    { // Network packet is empty. Problem. Skip it
        return NF_ACCEPT;
    }
    
    iph = ip_hdr(skb);
    if (!iph)
    { // Not IP. Skip it
        return NF_ACCEPT;
    }

    // save the address
    saddr = ntohl(iph->saddr);
    daddr = ntohl(iph->daddr);
    
    /* Calculate pointers for begin and end of IP packet data */
    pkt_data = (unsigned char *)((unsigned char *)iph);
    tail = skb_tail_pointer(skb);

    for (pSpamStrings = spam_strings; *pSpamStrings; ++pSpamStrings)
    { // Iterate over the spam strings.

        /* For each string walk the pkt data for a match.
         * On a match log to var/log/messages IP address and string
         * then return with a DROP
         */
        char const *pSpamString = *pSpamStrings;
        for (it = pkt_data; it != tail; ++it)
        {
            int ret;
            ret = memcmp((void *)((unsigned char *)it), (void *)((char const *)pSpamString), strlen(pSpamString));
            if (0 == ret)
            { // Match
                printk(KERN_INFO "Packet dropped! From %pi4 containing %s\n", &saddr, pSpamString);
                return NF_DROP;
            }
        }
    }

    return NF_ACCEPT;
} // hook_func

static int __init spam_init(void)
{
    int res = 0;
    
    nfho.hook     = (nf_hookfn *)hook_func;  // function to call when conditions below met

    // Select where to hook
    nfho.hooknum  = NF_INET_PRE_ROUTING;     // called right after packet recieved, first hook in Netfilter
    //nfho.hooknum  = NF_IP_LOCAL_IN;          // called after packet routed to local system

    nfho.pf       = PF_INET;                 // IPV4 packets
    nfho.priority = NF_IP_PRI_FIRST;         // set to highest priority over all other hook functions


    //res = nf_register_hook(&nfho);          // register hook
    if (res < 0)
    {
        prrintk("ERROR in nf_register_hook()\n");
        return res;
    }

    printk("spam: loaded\n");
    return 0;
}

static void __exit spam_exit(void)
{
    //nf_unregister_hook(&nfho);
    printk("spam: unloaded\n");
}

module_init(spam_init);
module_exit(spam_exit);

MODULE_AUTHOR("Gregg Rudshagen");
MODULE_DESCRIPTION("Module for spam filtering packet data");
MODULE_LICENSE("GPL");
