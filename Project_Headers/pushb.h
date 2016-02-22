/*
 * File: pushb.h
 *
 * Description
 *
 * Author
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * Computer Systems Engineering
 *
 */
#ifndef PUSHB_H_
#define PUSHB_H_

void pushb_init_A1(int n);
void pushb_init_A2(int n);
void pushb_init_A12(int n);
void pushb_init_D(int n);

int pushb_poll_A1(int n);
int pushb_poll_A2(int n);
int pushb_poll_A12(int n);
int pushb_poll_D(int n);
int pushb_poll_all();


#endif
