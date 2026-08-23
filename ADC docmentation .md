# STM32 ADC — Configuration Notes

Like any peripheral, the ADC needs to be initiated according to the registers available. Think of these as the **"features"** available to configure:

1. Resolution: 6, 8, 10, or 12 bits
2. Single / continuous mode
3. Choosing channels
4. Data alignment
5. Interrupt at the end of conversion (or not?)
6. Full speed or slower speed (chosen by changing the supply)
7. etc...

We need **2 main functions** to convert Analog to Digital: init ADC, and read ADC.

---

## A. Init ADC

### 1. Clock Config
The ADC clock is generated from the APB2 clock / prescaler.
> **Note:** The controller won't work unless the clock is set.

### 2. Enable ADC
Set the **ADON** bit in the `ADC_CR2` register.

### 3. Choose Channel

There are 2 types of channels:
- **Regular channels** — handle background or continuous sequential conversions.
- **Injected channels** — act like hardware interrupts to pause regular tasks for urgent, time-critical analog sampling.

In our task, we will just use the regular one, since there is no need for the injected channels.

A conversion can be a **sequence** of conversions (in case of using more than 1 channel) or just 1 channel.

So, to tell the ADC peripheral how many channels we have in general, we set the **L[3:0]** bits in the `ADC_SQR1` register:

| L[3:0] | Number of Conversions |
|--------|------------------------|
| 0000   | 1 conversion           |
| 0001   | 2 conversions          |
| ...    | ...                    |
| 1111   | 16 conversions         |

Now, we only have 1 channel in our "sequence," so when we configure the channel we'll be using, we go to the **SQ1** bit in the `ADC_SQRx` registers (there is `SQR1`, `SQR2`, `SQR3`) — you just search for the sequence number you have (which is 1 in our case).

For example, if I were to use channel 3, I would assign SQ1 = 3 (in hexadecimal, of course).

### 4. Choose Resolution
From the ADC Control Register 1 (`ADC_CR1`), bits 25 & 24.

### 5. Choose Conversion Mode
From bit 1 (**CONT**) in `ADC_CR2`:
- `0` → Single mode
- `1` → Continuous mode

### 6. Choose the Prescaler
From bits 17 & 16 (**ADCPRE**) in `ADC_CCR`:

| ADCPRE | PCLK2 Division |
|--------|-----------------|
| 00     | PCLK2 divided by 2 |
| 01     | PCLK2 divided by 4 |
| 10     | PCLK2 divided by 6 |
| 11     | PCLK2 divided by 8 |

---

## B. Read ADC

1. The result is in the ADC Regular Data Register, `ADC_DR` (bits 15:0). (needs to be stored or returned in another variable)
2. To start the conversion: in `ADC_CR2`, set bit 30 (**SWSTART**).
   > **Note:** This bit can only be set when `ADON = 1`, otherwise no conversion is launched.
3. To determine if the conversion is finished:
   - Check if bit 1 (**EOC**) in `ADC_SR` is set to 1 — if so, the conversion is done. *(polling choice)*
   - Trigger an interrupt event once the conversion is done: set bit 5 (**EOCIE**) in the `ADC_CR1` register. *(interrupt choice)*