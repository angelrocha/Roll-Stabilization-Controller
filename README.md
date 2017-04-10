# Roll-Stabilization-Controller
Arduino program intended to stabilize roll perturbations through aileron control
This program relies on the Arduino IDE to control servo deflection. There is a programmed IMU sensor to track perturbations from the steady state roll position. The IMU has an integrated high pass/low pass filter to filter out noise in gyroscope tracking. The servo deflects in response to IU sensor data. Additionally, a frequency sweep (chirp) and doublet are programmed in order to determine servo dynamics.
