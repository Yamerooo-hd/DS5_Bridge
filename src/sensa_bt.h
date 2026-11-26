#ifndef SENSA_BT_H
#define SENSA_BT_H

#include <cstdint>
#include "sensa_state.h"

namespace sensa {

bool bt_init();
void bt_poll();

void bt_start_pairing();
void bt_forget_all();
void bt_disconnect_now();
bool bt_start_sdp_discovery();

void bt_notify_host_output();
void bt_submit_haptic_waveform(int8_t const block[64], HapticMode proto);
void bt_set_override_led(uint8_t r, uint8_t g, uint8_t b);

bool bt_copy_cached_feature(uint8_t report_id, uint8_t *buf, uint16_t cap, uint16_t &copied);
void bt_send_set_feature(uint8_t report_id, uint8_t const *buf, uint16_t len);
void bt_debug_dump();
void bt_trigger_unlock_sequence();

} // namespace sensa

#endif
