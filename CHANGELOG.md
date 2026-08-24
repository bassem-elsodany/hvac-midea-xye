# Changelog

## [0.3.0](https://github.com/bassem-elsodany/hvac-midea-xye/compare/v0.2.9...v0.3.0) (2026-08-24)


### ⚠ BREAKING CHANGES

* requires ESPHome >= 2026.4.0. Users pulling this as external_components with an older ESPHome will fail to compile. The deprecated traits setters would still work on 2026.4.0-2026.11.0, but we migrate now to keep the codebase on supported APIs.

### Features

* add defrost active binary sensor ([#97](https://github.com/bassem-elsodany/hvac-midea-xye/issues/97)) ([#108](https://github.com/bassem-elsodany/hvac-midea-xye/issues/108)) ([0d67257](https://github.com/bassem-elsodany/hvac-midea-xye/commit/0d6725757fd2f0b6f7d8dbe7443f460021172771))
* compressor-aware climate action and diagnostic sensors ([#119](https://github.com/bassem-elsodany/hvac-midea-xye/issues/119)) ([e3cae9b](https://github.com/bassem-elsodany/hvac-midea-xye/commit/e3cae9b782a25a77ece362eeb130e678bcb49e7f))
* **midea_xye:** add decision and compact hex bus tracing logs ([18f356c](https://github.com/bassem-elsodany/hvac-midea-xye/commit/18f356c605dc4e7d3fa41439f243a4835dd4a245))
* **midea_xye:** add human-readable C0 trace text sensors ([41f60b8](https://github.com/bassem-elsodany/hvac-midea-xye/commit/41f60b89d9a31aa106c4b03db4ea986bfe88bed4))
* **midea_xye:** AUTO mode, C0 setpoint sync, and bus trace sensors ([5ba100b](https://github.com/bassem-elsodany/hvac-midea-xye/commit/5ba100b8dc454ef561decf2f1567b7e39df0eac5))
* migrate to ESPHome 2026.4.0 custom-mode API ([#100](https://github.com/bassem-elsodany/hvac-midea-xye/issues/100)) ([#105](https://github.com/bassem-elsodany/hvac-midea-xye/issues/105)) ([515f786](https://github.com/bassem-elsodany/hvac-midea-xye/commit/515f78659662ef2e487e4b76a7c3198e16e95361))
* sync HA fan mode from C4 target_fan_speed when sync_fan_mode_fr… ([#124](https://github.com/bassem-elsodany/hvac-midea-xye/issues/124)) ([9243612](https://github.com/bassem-elsodany/hvac-midea-xye/commit/9243612f27c9999b459d470184b009312bedcf83))


### Bug Fixes

* C0 bus is source of truth for mode — decouple display from AUTO logic ([1e6290f](https://github.com/bassem-elsodany/hvac-midea-xye/commit/1e6290f16d4231bc7b16b2911d1217f9756b9fb6))
* correct CLIMATE_FAN_OFF mapping and response_timeout, add XYEAdapter, remove TXData/RXData legacy pointers ([#83](https://github.com/bassem-elsodany/hvac-midea-xye/issues/83)) ([4e9ae8c](https://github.com/bassem-elsodany/hvac-midea-xye/commit/4e9ae8cd8bfc7919c8119f3eb8e0120d38604855))
* correct Fahrenheit setpoint reporting and C4 debug log ([#127](https://github.com/bassem-elsodany/hvac-midea-xye/issues/127)) ([6035f41](https://github.com/bassem-elsodany/hvac-midea-xye/commit/6035f4174ef5d06502d8e1985c6f7e2ca896b6b6))
* enable midea_xye on ESP-IDF for ESP32-C6 ([9be8eb3](https://github.com/bassem-elsodany/hvac-midea-xye/commit/9be8eb391028aeecceda58f4ecebd641c28011ab))
* greedy \x hex escape in setpoint debug log + CI lint to catch similar ([#132](https://github.com/bassem-elsodany/hvac-midea-xye/issues/132)) ([1f08726](https://github.com/bassem-elsodany/hvac-midea-xye/commit/1f087269539155245f129f3690ff95a74afa6de0))
* increase temperature sensor display precision to 2 decimal places ([#115](https://github.com/bassem-elsodany/hvac-midea-xye/issues/115)) ([d1b169c](https://github.com/bassem-elsodany/hvac-midea-xye/commit/d1b169c56fea8e531dc8b491363317afc181fc0e))
* Mask 0x40 bit from set temperature byte in C0 response parsing ([#73](https://github.com/bassem-elsodany/hvac-midea-xye/issues/73)) ([f008a52](https://github.com/bassem-elsodany/hvac-midea-xye/commit/f008a52b70e4dfa0840ef6510eb2d10c5c46b319))
* **midea_xye:** derive AUTO action from thermostat sub-mode not C0 bus ([ed0f740](https://github.com/bassem-elsodany/hvac-midea-xye/commit/ed0f7401126c9fa8a782124b826d32fee8ef82b7))
* **midea_xye:** fan decode, bus addressing, and native tests ([8354c35](https://github.com/bassem-elsodany/hvac-midea-xye/commit/8354c35246f48d2a4af6df3ae882e0e5723f6341))
* **midea_xye:** read setpoint from C0 when C4 extended query fails ([eb53e2a](https://github.com/bassem-elsodany/hvac-midea-xye/commit/eb53e2ac04d90f9859c9ce18da863ccd36a2cc88))
* **midea_xye:** recover RS-485 bus after bad UART responses ([2081b0e](https://github.com/bassem-elsodany/hvac-midea-xye/commit/2081b0ec69b16a9c3c0b80b72c908a56e3282484))
* **midea_xye:** use float current_temperature instead of optional ([693fb8d](https://github.com/bassem-elsodany/hvac-midea-xye/commit/693fb8dc6e3600fd4fe78dd9a16a2bfaa21b40f3))
* reboot HVAC ESPs after prolonged Wi-Fi loss ([1afe8be](https://github.com/bassem-elsodany/hvac-midea-xye/commit/1afe8beeb7c328547e577ca25298c0cf129cef09))
* reclassify C0 byte 19 as compressor-running flag and document bytes 28-29 steady-state values ([#112](https://github.com/bassem-elsodany/hvac-midea-xye/issues/112)) ([f47e54c](https://github.com/bassem-elsodany/hvac-midea-xye/commit/f47e54c243e40dd8026dafe571d88ba3473eaa42))
* reclassify C4 byte 17 as target fan speed ([#122](https://github.com/bassem-elsodany/hvac-midea-xye/issues/122)) ([cbf0210](https://github.com/bassem-elsodany/hvac-midea-xye/commit/cbf0210a71231f6260331d70260aa4e7121a9bb6))
* report correct action states for FAN_ONLY and DRY modes ([#129](https://github.com/bassem-elsodany/hvac-midea-xye/issues/129)) ([f0a4fc2](https://github.com/bassem-elsodany/hvac-midea-xye/commit/f0a4fc2f2d5921650bd3e433f6ae9a04017f0d7e))
* require conventional commits so release-please auto-generates releases ([#75](https://github.com/bassem-elsodany/hvac-midea-xye/issues/75)) ([ce1254f](https://github.com/bassem-elsodany/hvac-midea-xye/commit/ce1254f609ae86aeec27018b9bf3aeb7c2804617))
* stop C4 query from overwriting Celsius climate setpoint ([c9fa7a0](https://github.com/bassem-elsodany/hvac-midea-xye/commit/c9fa7a03abd856a3db2185fa13d7c7fd2b6a2087))
* suppress transient mode flap after SET ([#102](https://github.com/bassem-elsodany/hvac-midea-xye/issues/102)) ([#103](https://github.com/bassem-elsodany/hvac-midea-xye/issues/103)) ([fc56f99](https://github.com/bassem-elsodany/hvac-midea-xye/commit/fc56f997ea34fae086730083194bdb0a9b4e03e0))
* sync HA fan_mode from C0 physical speed (fixes AUTO vs MEDIUM divergence) ([f56daf9](https://github.com/bassem-elsodany/hvac-midea-xye/commit/f56daf93bc49f5e3ef30cb076c770db8837204e8))

## [0.2.9](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.8...v0.2.9) (2026-05-28)


### Bug Fixes

* greedy \x hex escape in setpoint debug log + CI lint to catch similar ([#132](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/132)) ([1f08726](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/1f087269539155245f129f3690ff95a74afa6de0))

## [0.2.8](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.7...v0.2.8) (2026-05-28)


### Bug Fixes

* correct Fahrenheit setpoint reporting and C4 debug log ([#127](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/127)) ([6035f41](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/6035f4174ef5d06502d8e1985c6f7e2ca896b6b6))

## [0.2.7](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.6...v0.2.7) (2026-05-27)


### Bug Fixes

* report correct action states for FAN_ONLY and DRY modes ([#129](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/129)) ([f0a4fc2](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/f0a4fc2f2d5921650bd3e433f6ae9a04017f0d7e))

## [0.2.6](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.5...v0.2.6) (2026-05-23)


### Features

* sync HA fan mode from C4 target_fan_speed when sync_fan_mode_fr… ([#124](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/124)) ([9243612](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/9243612f27c9999b459d470184b009312bedcf83))

## [0.2.5](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.4...v0.2.5) (2026-05-18)


### Bug Fixes

* reclassify C4 byte 17 as target fan speed ([#122](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/122)) ([cbf0210](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/cbf0210a71231f6260331d70260aa4e7121a9bb6))

## [0.2.4](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.3...v0.2.4) (2026-05-18)


### Features

* compressor-aware climate action and diagnostic sensors ([#119](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/119)) ([e3cae9b](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/e3cae9b782a25a77ece362eeb130e678bcb49e7f))

## [0.2.3](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.2...v0.2.3) (2026-05-17)


### Bug Fixes

* increase temperature sensor display precision to 2 decimal places ([#115](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/115)) ([d1b169c](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/d1b169c56fea8e531dc8b491363317afc181fc0e))

## [0.2.2](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.1...v0.2.2) (2026-05-17)


### Bug Fixes

* reclassify C0 byte 19 as compressor-running flag and document bytes 28-29 steady-state values ([#112](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/112)) ([f47e54c](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/f47e54c243e40dd8026dafe571d88ba3473eaa42))

## [0.2.1](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.2.0...v0.2.1) (2026-04-21)


### Features

* add defrost active binary sensor ([#97](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/97)) ([#108](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/108)) ([0d67257](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/0d6725757fd2f0b6f7d8dbe7443f460021172771))

## [0.2.0](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.1.7...v0.2.0) (2026-04-21)


### ⚠ BREAKING CHANGES

* requires ESPHome >= 2026.4.0. Users pulling this as external_components with an older ESPHome will fail to compile. The deprecated traits setters would still work on 2026.4.0-2026.11.0, but we migrate now to keep the codebase on supported APIs.

### Features

* migrate to ESPHome 2026.4.0 custom-mode API ([#100](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/100)) ([#105](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/105)) ([515f786](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/515f78659662ef2e487e4b76a7c3198e16e95361))

## [0.1.7](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.1.6...v0.1.7) (2026-04-21)


### Bug Fixes

* suppress transient mode flap after SET ([#102](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/102)) ([#103](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/103)) ([fc56f99](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/fc56f997ea34fae086730083194bdb0a9b4e03e0))

## [0.1.6](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.1.5...v0.1.6) (2026-04-08)


### Bug Fixes

* correct CLIMATE_FAN_OFF mapping and response_timeout, add XYEAdapter, remove TXData/RXData legacy pointers ([#83](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/83)) ([4e9ae8c](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/4e9ae8cd8bfc7919c8119f3eb8e0120d38604855))

## [0.1.5](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.1.4...v0.1.5) (2026-04-05)


### Bug Fixes

* Mask 0x40 bit from set temperature byte in C0 response parsing ([#73](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/73)) ([f008a52](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/f008a52b70e4dfa0840ef6510eb2d10c5c46b319))

## [0.1.4](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.1.3...v0.1.4) (2026-04-05)


### Bug Fixes

* require conventional commits so release-please auto-generates releases ([#75](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/75)) ([ce1254f](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/ce1254f609ae86aeec27018b9bf3aeb7c2804617))

## [0.1.3](https://github.com/HomeOps/ESPHome-Midea-XYE/compare/v0.1.2...v0.1.3) (2026-04-05)


### Bug Fixes

* require conventional commits so release-please auto-generates releases ([#75](https://github.com/HomeOps/ESPHome-Midea-XYE/issues/75)) ([ce1254f](https://github.com/HomeOps/ESPHome-Midea-XYE/commit/ce1254f609ae86aeec27018b9bf3aeb7c2804617))
