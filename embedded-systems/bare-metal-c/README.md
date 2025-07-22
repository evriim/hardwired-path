# Bare-Metal C Programming ⚙️💾

**Welcome!**  
This folder documents my learning and experimentation with **bare-metal C programming**, where I interact directly with hardware **without any operating system or abstraction layers**.

---

## 📌 What is Bare-Metal C?

*Bare-metal programming* means writing code that runs directly on the hardware, typically on a **microcontroller**, without the help of an OS, runtime libraries, or drivers.

This style of development is essential for:
- Real-time systems
- Embedded applications with strict resource constraints
- Learning how microcontrollers actually work at the register level

> 🧠 Bare-metal = Full control over hardware  
> 🛠️ But also = Full responsibility for everything (timing, memory, safety)

---

## 🎯 Why I’m Learning This

As a computer engineering student focusing on embedded systems, I want to go beyond Arduino-style abstractions and:
- Understand memory-mapped registers
- Work with hardware timers, interrupts, and GPIO directly
- Learn to initialize and configure peripherals manually
- Explore startup files, linker scripts, and vector tables

---

## 🧭 Learning Path

Here are the main topics I plan to cover or have already studied:

- 🔧 Microcontroller Architecture (ARM Cortex-M, AVR, etc.)
- 🧠 Startup Process (reset vector, stack pointer, initialization)
- 🪢 Linker Scripts & Memory Mapping
- ⚡ GPIO: Controlling pins directly via registers
- ⏱️ Timers & Delays (SysTick, hardware timers)
- 📞 Interrupts & NVIC
- 🔌 UART, I2C, SPI via register-level control
- 💾 Flash & EEPROM memory
- 🧪 Testing with real boards or simulators (QEMU, STM32F103, etc.)

---

## 🎥 Resources I Followed

Here are some of the tutorials and guides I used while working with Arduino:

- [Cosmic Aerospace](https://www.youtube.com/@CosmicAerospace)  
- 
- 
- 

---


## ⚠️ Notes

* This is **not Arduino**. There is no `digitalWrite()`, no delay function — everything is done by directly writing to memory addresses and registers.
* Make sure to refer to your microcontroller's **datasheet** and **reference manual** before using peripherals.

---

Thanks for checking it out!
This is an ongoing journey — I’ll continue updating as I learn more.

```
