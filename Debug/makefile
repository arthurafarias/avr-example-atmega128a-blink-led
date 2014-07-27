################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AVRTest.lss \

FLASH_IMAGE += \
AVRTest.hex \

EEPROM_IMAGE += \
AVRTest.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: AVRTest.elf secondary-outputs

# Tool invocations
AVRTest.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVRTest.map -mmcu=atmega128 -o "AVRTest.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVRTest.lss: AVRTest.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVRTest.elf  >"AVRTest.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVRTest.hex: AVRTest.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVRTest.elf  "AVRTest.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVRTest.eep: AVRTest.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVRTest.elf  "AVRTest.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVRTest.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 AVRTest.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: AVRTest.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm128 -cusbasp -u -Uflash:w:AVRTest.hex:a -Ueeprom:w:AVRTest.eep:a -Ulfuse:w:0x1e:m -Uhfuse:w:0xcf:m -Uefuse:w:0xff:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) AVRTest.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
