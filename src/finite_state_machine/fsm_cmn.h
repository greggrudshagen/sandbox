#ifndef FSM_CMN_H
#define FSM_CMN_H

extern void *InitState(int state);
extern void *NorthState(int state);
extern void *SouthState(int state);
extern void *EastState(int state);
extern void *WestState(int state);

extern int const FSM_STATE_INIT;
extern int const FSM_STATE_NORTH;
extern int const FSM_STATE_SOUTH;
extern int const FSM_STATE_EAST;
extern int const FSM_STATE_WEST;
extern int const FSM_STATE_LAST; // always last





#endif /* FSM_CMN_H */
