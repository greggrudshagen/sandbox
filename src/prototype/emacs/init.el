



(defconst my-c-style
  '("GDRCSTYLE"
    (c-basic-offset . 4)
    (c-tab-always-indent . nil)
    (c-offsets-alist . ((access-label . 0)
                        (defun-open . 0)
                        (defun-block-intro . 4)
                        (statement-block-intro . 4)
                        (substatement . +)
                        (substatement-open . 0)
                        (brace-list-open . +)
                        (brace-list-intro . 0)
                        (statement-case-open . 0)
                        (statement-case-intro . 4)
                        (case-label . +)
                        (class-open . 0)
                        (class-close . 0)
                        (topmost-intro . 0)
                        (label . 0)
                        (inline-open . 0)))
    (c-cleanup-list  . (brace-else-brace
                        scope-operator
                        empty-defun-braces
                        defun-close-semi))
    )
  "My C indentation style")
(defun my-c-mode-common-hook ()
  ;; set up for my perferred indentation style, but only do it once
  (let ((my-style "GDRCSTYLE"))
    (or (assoc my-style c-style-alist)
        (setq c-style-alist (cons my-c-style c-style-alist)))
    (c-set-style my-style))
  ;; offset customizations not in my-style
  ;;(c-set-offset 'block-open 'c-adaptive-block-open)
  (c-set-offset 'member-init-intro (* 2 c-basic-offset))
  ;; keybindings for both C and C++. We can put these in c-mode-map
  ;; because c++-mode-map inherits it
  (define-key c-mode-map "\C-m" 'newline-and-indent)
  )

(add-hook 'c-mode-common-hook 'my-c-mode-common-hook)
(add-hook 'c-mode-common-hook 'turn-on-font-lock)

(setq font-lock-maximum-decoration
 '((c-mode . 3) (c++-mode . 3) (java-mode . 3) )) ; medium strength hi-liting (2)
;;Turn off some annoying keys.
(global-unset-key "\e\e")
(global-unset-key "\C-x\C-u")
;(global-unset-key "\C-x\C-c")
(setq hippie-expand-try-functions-list '(try-expand-all-abbrevs try-expand-list try-expand-dabbrev try-expand-dabbrev-all-buffers try-expand-dabbrev-from-kill try-complete-lisp-symbol-partially try-complete-lisp-symbol))

;; Now tell emacs that HPP is a c-mode type file
;(setq auto-mode-alist (cons '("\.hpp$". c++-mode) auto-mode-alist))
;(setq auto-mode-alist (cons '("\.h$". c++-mode) auto-mode-alist))
;(setq auto-mode-alist (cons '("\.mq4$". c++-mode) auto-mode-alist))
;(add-to-list 'auto-mode-alist '("\\.mq4\\'" . cc-mode))
;(setq auto-mode-alist (cons '("\.java$". c++-mode) auto-mode-alist))
;;(require 'crypt)
;-----
;(setq user-mail-address "noname@nowhere.com")
;(setq user-full-name "noname")
;(setq mail-default-reply-to "noname@nowhere.com")
;(setq mail-archive-file-name "~/mail/sent-mail")
;(setq mail-yank-prefix "> ")
;(load-library "message")
;(setq message-send-mail-function 'smtpmail-send-it)
;(autoload 'gnus-group-mail "gnus-msg" "Send a mail message using gnus." t)
;-----
(require 'paren)
(setq mail-signature t)
(setq auto-save-default nil)
(setq make-backup-files nil)
;;(custom-set-variables)
(add-hook 'c-mode-common-hook
 '(lambda ()
 (auto-fill-mode)
 (set-fill-column 1000)
 ))
(add-hook 'HTML-mode--hook
 '(lambda ()
 (auto-fill-mode)
 (set-fill-column 1000)
 ))
;; obsolete?? (setq default-fill-column 1000) ; the column beyond which do word wrap
(setq fill-column 1000) ; the column beyond which do word wrap
(setq sgml-indent-data t)
(setq sgm-set-face t)
;;(toggle-text-mode-auto-fill)
(auto-fill-mode)
;(set-fill-column 1000)
(modify-face font-lock-comment-face "SlateGrey" nil nil nil nil nil)
(setq column-number-mode t)
;; DOESNT WORK FOR WinEmacs ;; (server-start)
;;(custom-set-faces
;; '(font-lock-comment-face ((((class color) (background dark)) (:foreground "Red")))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(region ((t (:background "Blue"))))
 '(show-paren-match-face ((((class color)) (:foreground "NavyBlue" :background "turquoise")))))
(setq load-path (append load-path
 (list "~/emacs/")))
;(load "lees-default")
;(load "cua-mode.el")
;(cua-mode t)
(setq-default truncate-lines 1)
(define-key global-map [S-tab] 'CUA-cmd-indent-region-right)
;;((setq load-path (append load-path(cons (list "/usr/local/src/w3"))
(set-scroll-bar-mode 'right)
(setq scroll-step 1)
(defun my-skrol-down ()
 (interactive)
 (scroll-down 5)
 )
(defun my-skrol-up ()
 (interactive)
 (scroll-up 5)
 )
;(define-key global-map [mouse-4] 'scroll-down) ; scroll-down
;(define-key global-map [mouse-5] 'scroll-up) ; scroll-up
(define-key global-map [mouse-4] 'my-skrol-down) ; scroll-down
(define-key global-map [mouse-5] 'my-skrol-up) ; scroll-up
;(setq load-path (append load-path (list "~/emacs/java")))
;(load "speedbar.el")
;(load "jde.el")
;(load "java-compile")
;(load "java-font-lock-20a.el")
;(load "hack-aplvr.el")
;(setq tab-width 4)
;(setq load-path (append load-path (list "~/emacs/java")))
;(load "java-font-lock-20a.el")
(global-set-key [(meta backspace)] 'backward-kill-word)
(global-set-key [(meta return)] 'find-file-at-point) ;; Open the file at cursor
;(setq default-frame-alist '((font . "-adobe-courier-medium-r-normal--12-120-75-75-m-70-iso10646-1") (top . 10) (left . 30)))
(custom-set-variables
 '(truncate-lines 1)
)
(custom-set-variables ; tabs to spaces
 '(tab-width 4)
 '(indent-tabs-mode nil))
; '(hscroll-mode-name " ")
; '(hscroll-margin 5)
; '(hscroll-snap-threshold 30)
; '(next-line-add-newlines nil)
; '(hscroll-global-mode t nil (hscroll)))
(add-hook 'c-mode-hook
 (lambda ()
 (setq show-trailing-whitespace t)
 (make-local-hook 'before-save-hook)
 (add-hook 'before-save-hook 'delete-trailing-whitespace)))
;(require 'blank-mode)
; ---------------- matching word pairs ------------------
; The idea here is that while emacs has built-in support for matching
; things like parentheses, I work with a variety of syntaxes that use
; balanced keyword pairs, such as "begin" and "end", or "#if" and
; "#endif". So this mechanism searches for the balanced element
; of such ad-hoc constructions.
;
; TODO: Currently, there is no support for skipping things that are
; in string literals, comments, etc. I think that would be possible
; just by having appropriate regexs for them and skipping them when
; they occur, but I haven't tried yet.
(defun find-matching-element (search-func offset open-regex close-regex)
 "Search forwards or backwards (depending on `search-func') to find
 the matching pair identified by `open-regex' and `close-regex'."
 (let ((nesting 1) ; number of pairs we are inside
 (orig-point (point)) ; original cursor loc
 (orig-case-fold-search case-fold-search))
 (setq case-fold-search nil) ; case-sensitive search
 (goto-char (+ (point) offset)) ; skip the `open-regex' at cursor
 (while (and (> nesting 0)
 (funcall search-func
 (concat "\\(" open-regex "\\)\\|\\(" close-regex "\\)") nil t))
 (if (string-match open-regex (match-string 0))
 (setq nesting (+ nesting 1))
 (setq nesting (- nesting 1))
 ))
 (setq case-fold-search orig-case-fold-search)
 (if (eq nesting 0)
 ; found the matching word, move cursor to the beginning of the match
 (goto-char (match-beginning 0))
 ; did not find the matching word, report the nesting depth at EOF
 (progn
 (goto-char orig-point)
 (error (format "Did not find match; nesting at file end is %d" nesting))
 )
 )))
; This is what I bind to Alt-[ and Alt-].
(defun find-matching-keyword ()
 "Find the matching keyword of a balanced pair."
 (interactive)
 (cond
 ; these first two come from lisp/emulation/vi.el
 ((looking-at "[[({]") (forward-sexp 1) (backward-char 1))
 ((looking-at "[])}]") (forward-char 1) (backward-sexp 1))
; C/C++
 ((looking-at "#if")
 (find-matching-element 're-search-forward 3 "#if" "#endif"))
 ((looking-at "#else")
 (find-matching-element 're-search-forward 3 "#if" "#endif"))
 ((looking-at "#elif")
 (find-matching-element 're-search-forward 3 "#if" "#endif"))
 ((looking-at "#endif")
 (find-matching-element 're-search-backward 0 "#endif" "#if"))
; C/C++
 ((looking-at "define")
 (find-matching-element 're-search-forward 6 "define" "endef"))
 ((looking-at "endef")
 (find-matching-element 're-search-backward 0 "endef" "define" ))
((looking-at "ifeq")
 (find-matching-element 're-search-forward 4 "\\(ifeq\\)\\|\\(ifneq\\)\\|\\(ifdef\\)\\|\\(ifndef\\)" "\\(endif\\)"))
 ((looking-at "ifneq")
 (find-matching-element 're-search-forward 5 "\\(ifeq\\)\\|\\(ifneq\\)\\|\\(ifdef\\)\\|\\(ifndef\\)" "\\(endif\\)"))
 ((looking-at "ifdef")
 (find-matching-element 're-search-forward 4 "\\(ifeq\\)\\|\\(ifneq\\)\\|\\(ifdef\\)\\|\\(ifndef\\)" "\\(endif\\)"))
 ((looking-at "ifndef")
 (find-matching-element 're-search-forward 4 "\\(ifeq\\)\\|\\(ifneq\\)\\|\\(ifdef\\)\\|\\(ifndef\\)" "\\(endif\\)"))
 ((looking-at "else")
 (find-matching-element 're-search-forward 4 "\\(ifeq\\)\\|\\(ifneq\\)\\|\\(ifdef\\)\\|\\(ifndef\\)" "\\(endif\\)"))
 ((looking-at "endif")
 (find-matching-element 're-search-backward 0 "\\(endif\\)" "\\(ifeq\\)\\|\\(ifneq\\)\\|\\(ifdef\\)\\|\\(ifndef\\)"))
;(t (error "Cursor is not on ASSERT nor RETRACT"))
 (t t)
 ))
(defun find-matching-keyword-prev ()
 "Find the matching keyword of a balanced pair."
 (interactive)
 (cond
 ; these first two come from lisp/emulation/vi.el
 ((looking-at "[[({]") (forward-sexp 1) (backward-char 1))
 ((looking-at "[])}]") (forward-char 1) (backward-sexp 1))
; C/C++
 ((looking-at "#if")
 (find-matching-element 're-search-forward 3 "#if" "#endif"))
 ((looking-at "#endif")
 (find-matching-element 're-search-backward 0 "#endif" "#if"))
((looking-at "ifeq")
 (find-matching-element 're-search-forward 4 "if[n]*eq" "endif"))
 ((looking-at "ifneq")
 (find-matching-element 're-search-forward 5 "if[n]eq" "endif")) ((looking-at "endif")
 (find-matching-element 're-search-backward 0 "endif" "if[n]*eq"))
;(t (error "Cursor is not on ASSERT nor RETRACT"))
 (t t)
 ))
(global-set-key [(meta ?])] 'find-matching-keyword)
;(prefer-coding-system 'unix) ; hmm this doesnt work.. can set file's coding to unix but can't prefer, why??
;(prefer-coding-system 'utf8)
;(setq coding-system-for-read 'utf-8)
;(setq coding-system-for-write 'utf-8)
;(global-set-key [(meta return)] 'bc-set) ;; Shift-SPACE for set bookmark
;(global-set-key [(meta f10)] 'bc-list) ;; C-x M-j for the bookmark menu list
;(global-set-key [(meta f11)] 'bc-previous) ;; M-j for jump to previous
;(global-set-key [(meta f12)] 'bc-next) ;; Shift-M-j for jump to next
;; (global-set-key [(shift meta j)] 'bc-next) ;; Shift-M-j for jump to next
;; (global-set-key [(meta up)] 'bc-local-previous) ;; M-up-arrow for local previous
;; (global-set-key [(meta down)] 'bc-local-next) ;; M-down-arrow for local next
;; (global-set-key [(control c)(j)] 'bc-goto-current) ;; C-c j for jump to current bookmark
(define-key global-map [C-S-f12] 'toggle-truncate-lines)
;(require 'php-mode)
;;(require 'breadcrumb)
;(load "compile-")
;(load "compile+")
;(load "grep+")
;(setq grep-command "grep -nH -r --exclude-dir='svn' --include='*.h' --include='*.cpp' --include='*.c' -e SrchStr *")
;(setq grep-find-command "find . -type f '!' -wholename '*/.git/*' -print0 | xargs -0 -e grep -nH -e ")
;(setq grep-find-command "find . -type f '!' \( -wholename '*/.git/*' -o -name "*.o" \) -print0 | xargs -0 -e grep -nH -w -e ")
;(which-func-mode 1)
