# **STM32-Based Modbus RTU Soil TH/NPK and Environmental Monitor**

## **Overview**

This system is an industrial-grade environmental monitoring node designed to precisely measure soil health parameters in real time. Utilizing an **STM32 microcontroller** as the primary processing core, the system interfaces with an industrial multi-parameter soil probe via an **RS485 physical layer**. The firmware implements the **Modbus RTU protocol** to query and parse critical agronomic data—including **Temperature, Humidity, pH, Nitrogen (N), Phosphorus (P), Potassium (K), Salinity, and Total Dissolved Solids (TDS)**—for localized processing and data forwarding.

---

## **Key Features**

### **STM32 Microcontroller Core**

* Leverages low-power hardware **UART peripherals** and **DMA channels** to handle high-frequency sensor querying, data parsing, and system logic efficiently.
* Utilizes dedicated hardware resources to minimize CPU overhead during continuous sensor acquisition.

### **Modbus RTU Protocol Engine**

* Custom-engineered C firmware implementing robust master-node **Modbus RTU packet construction**.
* Automatically generates and validates **16-bit Cyclic Redundancy Check (CRC-16)** values to ensure data integrity.
* Provides reliable communication with industrial sensors operating over RS485 networks.

### **TTL-to-RS485 Differential Interface**

* Integrates a hardware transceiver circuit to convert logic-level UART signals into differential **RS485 signals**.
* Enables long-distance, noise-immune communication with the submerged soil probe.
* Supports reliable operation in electrically noisy outdoor environments.

### **Multi-Parameter Sensor Register Mapping**

* Dynamically parses raw hexadecimal data payloads retrieved from sensor holding registers.
* Converts register values into calibrated, human-readable environmental measurements.
* Processes soil macronutrients (**Nitrogen, Phosphorus, and Potassium**) along with moisture, pH, salinity, and TDS metrics.

### **Industrial Signal Conditioning**

* Implements sensor power sequencing for stable system startup and operation.
* Incorporates **Transient Voltage Suppression (TVS)** protection on RS485 communication lines.
* Protects sensitive digital circuitry from electrical transients, environmental interference, and ground loop effects.

---

## **Hardware Integration & Prototyping Strategy**

The prototype utilizes a **dual-rail power scheme**, isolating the high-voltage **5–30V DC** external power loop required by the industrial soil probe from the sensitive **3.3V logic** of the STM32 and TTL-to-RS485 transceiver module.

To eliminate floating receiver inputs and data corruption caused by common-mode voltage offsets, a **uniform common ground matrix** connects all independent power domains.

**Logic level shifters** are integrated into the control paths where necessary to protect the microcontroller's input pins from voltage spikes.

Additionally, physical layer signaling and protocol compliance were validated using an **oscilloscope** and **logic analyzer** to:

* Decode UART waveforms
* Isolate timing jitter
* Resolve half-duplex direction-switching bottlenecks on the RS485 transceiver
* Verify communication integrity between the STM32 and industrial soil sensor
