// Copyright 2021 Takashi Toyoshima <toyoshim@gmail.com>. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef __usb_device_h__
#define __usb_device_h__

#include <stdint.h>

#include "interrupt.h"

extern void usb_int() __interrupt INT_NO_USB __using 1;

struct usb_device {
  uint8_t (*get_descriptor_size)(uint8_t type, uint8_t no);
  const uint8_t* (*get_descriptor)(uint8_t type, uint8_t no);
  uint8_t (*ep1_in)(uint8_t* buffer);
};

void usb_device_init(struct usb_device* device);

#endif  // __usb_device_h__