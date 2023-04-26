# STM32F429I-DISC1 Projects

Demo projects for STM32F429I-DISC1 boards

## Docker Usage

All target must build in docker, to build docker image, use command below:

```bash
./docker/build.sh
```

Run docker and copy project code into container use command below:

```bash
./docker/run.sh
```

## Build Target

When in container, start build target with command:

```bash
./build.sh
```

Or it can simply done with docker execute command (run outside container):

```bash
./docker/run.sh ./build.sh
```

## Run and Test

Flash `stm32f429i-disc1.bin` into STM32 MCU to run program, there is a sample of [OpenOCD](https://openocd.org/)

1. Install OpenOCD
2. Plug in stlink into your PC and attach MCU with stlink
3. Execute download.sh and wait the download progress done
4. All done!

## Peripheral Implements

- [x] GPIO
- [x] UART/USART
- [ ] SPI
- [ ] I2C
- [ ] ADC
- [ ] DAC
- [ ] TIM_PWM
- [ ] LCD (LTDC)
- [x] SW_PWM