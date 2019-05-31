#ifndef FSM_CMN_H
#define FSM_CMN_H

#include <stdc_version.h>

extern void *InitState(int32_t state);
extern void *NorthState(int32_t state);
extern void *SouthState(int32_t state);
extern void *EastState(int32_t state);
extern void *WestState(int32_t state);

extern int32_t const FSM_STATE_INIT;
extern int32_t const FSM_STATE_NORTH;
extern int32_t const FSM_STATE_SOUTH;
extern int32_t const FSM_STATE_EAST;
extern int32_t const FSM_STATE_WEST;
extern int32_t const FSM_STATE_LAST; // always last





#endif /* FSM_CMN_H */
