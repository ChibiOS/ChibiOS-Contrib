/*
    Copyright 2024 Xael South

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

#pragma once

enum xmlmbus_interface_ioctl {

    XMLMBUS_INTERFACE_IOCTL_CREATE_SND_NKE = 0,
    XMLMBUS_INTERFACE_IOCTL_CREATE_PACKET,
    XMLMBUS_INTERFACE_IOCTL_SET_BAUDRATE_300,
    XMLMBUS_INTERFACE_IOCTL_SET_BAUDRATE_2400,
    XMLMBUS_INTERFACE_IOCTL_SET_BAUDRATE_9600,
    XMLMBUS_INTERFACE_IOCTL_FLUSH_RX,
    XMLMBUS_INTERFACE_IOCTL_FLUSH_TX,
    XMLMBUS_INTERFACE_IOCTL_FLUSH_RXTX,
    XMLMBUS_INTERFACE_IOCTL_RESET_DEVICE,
    XMLMBUS_INTERFACE_IOCTL_SET_OPEN_FD_LATER,
    XMLMBUS_INTERFACE_IOCTL_RESET_INTERFACE_ERRORS,
};

