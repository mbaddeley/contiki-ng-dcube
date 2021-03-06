/*
 * Copyright (c) 2015, Nordic Semiconductor
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
/**
 * \addtogroup nrf52840
 * @{
 *
 * \file
 *         Architecture dependent rtimer implementation header file.
 * \author
 *         Wojciech Bober <wojciech.bober@nordicsemi.no>
 *
 */
/*---------------------------------------------------------------------------*/
#ifndef RTIMER_ARCH_H_
#define RTIMER_ARCH_H_
/*---------------------------------------------------------------------------*/
#include "contiki.h"

// HACK: This is a terrible way to do this. See rtimer-arch.c
#define NRF_RTIMER_NOW()        nrf_rtimer_now()
#define RTIMER_MILLISECOND      (RTIMER_ARCH_SECOND/1000)
#define RTIMER_MICROSECOND      (RTIMER_MILLISECOND/1000) // FIXME!!!! WILL BLOW UP ON SKY!!!!!
#define RTIMER_TICKS_TO_MS(T)   (uint16_t)((T)/RTIMER_MILLISECOND)
#define RTIMER_TICKS_TO_US(T)   (uint32_t)((T)/RTIMER_MICROSECOND)
#define RTIMER_MS_TO_TICKS(ms)  ((RTIMER_MILLISECOND*(ms)))
#define RTIMER_US_TO_TICKS(us)  ((RTIMER_MICROSECOND*(us)))
#define RTIMER_TICKS_HALF_US    8

/*---------------------------------------------------------------------------*/
rtimer_clock_t rtimer_arch_now(void);
/*---------------------------------------------------------------------------*/
#endif /* RTIMER_ARCH_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 */
