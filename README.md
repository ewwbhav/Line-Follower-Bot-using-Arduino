# Line-Follower
Line Follower Robot using Arduino Uno, L293D, N20 Motors, and QTR-8 Sensors — with smooth PID control and junction detection for competition-ready tracking.
# 🛣️ Line Follower Robot (Arduino Uno + QTR-8 + L293D + N20 Motors)

This is a high-performance **line-following robot** built using an **Arduino Uno**, an **L293D motor driver**, and a **QTR-8A analog IR sensor array**. It uses a custom **PID control algorithm** to follow black lines on white surfaces and includes support for **junction detection** like T-junctions, crossroads, and left/right splits.

Perfect for competitions or learning about autonomous robotics!

---

##  Features

- PID-based line following for smooth control
- Proportional motor speed based on line position
- Detects T-junctions, crossroads, and L/R turns
- Compact and efficient with N20 gear motors
- Built using Arduino Uno and programmed via Arduino IDE

---

## Hardware Components

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| L293D Motor Driver IC  | 1        |
| N20 Gear Motors        | 2        |
| QTR-8A Analog Sensor   | 1        |
| Li-ion Battery Pack (7.4V) | 1    |
| Robot Chassis, Wheels, Mounts | 1 set |

---

##  Software & Libraries

- Arduino IDE
- `QTRSensors` library for sensor calibration
- Custom PID logic (no motor shield libraries used)

---

## 🏁 Track Specifications

- Line color: **Black**
- Surface: **White**
- Line width: **Approximately 3cm**
- Includes: **Turns, T-junctions, crossroads**

---

##  How It Works

1. The QTR-8 sensor reads reflected IR light from the surface.
2. Analog values are used to calculate the line’s position.
3. A PID algorithm adjusts left and right motor speeds accordingly.
4. Additional logic handles junctions and intersections.

---

## 📸 Media

[Watch the test](https://drive.google.com/file/d/15DaXyZ0le-dNE7H-1j3aGisXQl89BcCx/view?usp=sharing)
---

## 📎 License

MIT License — feel free to use, modify, and share!

---

## 🙌 Credits
@ewwbhav

Special thanks to open-source libraries and the Arduino community!
