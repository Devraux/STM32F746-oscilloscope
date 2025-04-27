# DISCOVERY STM32F746ng oscilloscope
## Square wave
![Visitor Badge](https://visitor-badge.laobi.icu/badge?page_id=Devraux.STM_Discovery_Oscilloscope)

## ECG signal(10kHz)
![ecg](https://github.com/user-attachments/assets/22ec62c3-2c5e-4f00-8f5f-8afbf0072319)

## Sine signal(120kHz)
![sin](https://github.com/user-attachments/assets/3abdbcee-0449-47b0-80c3-6fff6e3fd952)

## Project version: 1.4) 

## Square Wave test (STM32 PWM)
![Image](https://github.com/user-attachments/assets/235eb390-0308-4c4e-85d1-41bb358b9d34)

# Todo:
- [x] LVGL configuration( LVGL[window drawer] -> FMC[Flexible Memory Control] -> LTDC driver) 
- [x] DISCOVERY external SDRAM connection with LTDC/FMC
- [x] STM32F746 hardware configuration - ADC(circular mode), DMA(double buffering, circular mode), FMC, LTDC
- [x] DMA double buffering mode configuration
- [x] Math tool(basic version) 
- [x] Project optimization and code refactoring
- [x] STOP/RUN feature implementation
- [x] Osiclooscope self test(external PWM generator based on same chip)
- [ ] Simple manual user interface - buttons and encoders
- [ ] horizontal and vertical stretching
- [ ] ADC performance improvement(sampling)
- [ ] Cursors
- [ ] DS/AC COUPLING
- [ ] PCB hardware fabrication
- [ ] Signal attenuation feature and offset manage(remove or add offset) 
- [ ] Additional options
- [ ] Advanced testing(bandwidth etc.)
- [ ] DSP features(hardware(STM32F746 FPU)) like FFT etc.
