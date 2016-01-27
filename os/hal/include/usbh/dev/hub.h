/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio
              Copyright (C) 2015 Diego Ismirlian, TISA, (dismirlian (at) google's mail)

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef USBH_HUB_H_
#define USBH_HUB_H_

#include "usbh.h"

#if HAL_USE_USBH
#if HAL_USBH_USE_HUB

typedef struct USBHHubDriver {
	/* inherited from abstract class driver */
	_usbh_base_classdriver_data

	struct list_head node;

	usbh_ep_t epint;
	usbh_urb_t urb;

	USBH_DEFINE_BUFFER(uint8_t, scbuff[4]);
	volatile uint32_t statuschange;
	uint16_t status;
	uint16_t c_status;

	usbh_port_t *ports;

	USBH_DEFINE_BUFFER(usbh_hub_descriptor_t, hubDesc);

	/* Low level part */
	_usbh_hub_ll_data

} USBHHubDriver;

extern USBHHubDriver USBHHUBD[HAL_USBHHUB_MAX_INSTANCES];


usbh_urbstatus_t usbhhubControlRequest(USBHDriver *host, USBHHubDriver *hub,
											uint8_t bmRequestType,
											uint8_t bRequest,
											uint16_t wValue,
											uint16_t wIndex,
											uint16_t wLength,
											uint8_t *buf);


static inline usbh_urbstatus_t usbhhubClearFeaturePort(usbh_port_t *port, uint8_t feature) {
	return usbhhubControlRequest(port->device.host, port->hub,
				USBH_REQTYPE_OUT | USBH_REQTYPE_CLASS | USBH_REQTYPE_OTHER,
				USBH_REQ_CLEAR_FEATURE,
				feature,
				port->number,
				0,
				0);
}

static inline usbh_urbstatus_t usbhhubClearFeatureHub(USBHDriver *host, USBHHubDriver *hub, uint8_t feature) {
	return usbhhubControlRequest(host, hub,
				USBH_REQTYPE_OUT | USBH_REQTYPE_CLASS | USBH_REQTYPE_DEVICE,
				USBH_REQ_CLEAR_FEATURE,
				feature,
				0,
				0,
				0);
}

static inline usbh_urbstatus_t usbhhubSetFeaturePort(usbh_port_t *port, uint8_t feature) {
	return usbhhubControlRequest(port->device.host, port->hub,
				USBH_REQTYPE_OUT | USBH_REQTYPE_CLASS | USBH_REQTYPE_OTHER,
				USBH_REQ_SET_FEATURE,
				feature,
				port->number,
				0,
				0);
}

void usbhhubObjectInit(USBHHubDriver *hubdp);
#else

static inline usbh_urbstatus_t usbhhubControlRequest(USBHDriver *host,
											uint8_t bmRequestType,
											uint8_t bRequest,
											uint16_t wValue,
											uint16_t wIndex,
											uint16_t wLength,
											uint8_t *buf) {
		return usbh_lld_root_hub_request(host, bmRequestType, bRequest, wValue, wIndex, wLength, buf);
}

static inline usbh_urbstatus_t usbhhubClearFeaturePort(usbh_port_t *port, uint8_t feature) {
	return usbhhubControlRequest(port->device.host,
				USBH_REQTYPE_OUT | USBH_REQTYPE_CLASS | USBH_REQTYPE_OTHER,
				USBH_REQ_CLEAR_FEATURE,
				feature,
				port->number,
				0,
				0);
}

static inline usbh_urbstatus_t usbhhubClearFeatureHub(USBHDriver *host, uint8_t feature) {
	return usbhhubControlRequest(host,
				USBH_REQTYPE_OUT | USBH_REQTYPE_CLASS | USBH_REQTYPE_DEVICE,
				USBH_REQ_CLEAR_FEATURE,
				feature,
				0,
				0,
				0);
}

static inline usbh_urbstatus_t usbhhubSetFeaturePort(usbh_port_t *port, uint8_t feature) {
	return usbhhubControlRequest(port->device.host,
				USBH_REQTYPE_OUT | USBH_REQTYPE_CLASS | USBH_REQTYPE_OTHER,
				USBH_REQ_SET_FEATURE,
				feature,
				port->number,
				0,
				0);
}

#endif

#endif

#endif /* USBH_HUB_H_ */
