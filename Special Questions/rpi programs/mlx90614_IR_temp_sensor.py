import board
import busio as io
import adafruit_mlx90614

# the mlx90614 must be run at 100k [normal speed]
# i2c default mode is is 400k [full speed]
# the mlx90614 will not appear at the default 400k speed
i2c = io.I2C(board.SCL, board.SDA, frequency=100000)
mlx = adafruit_mlx90614.MLX90614(i2c)

# temperature results in celsius
print("Ambent Temp: ", mlx.ambient_temperature)
print("Object Temp: ", mlx.object_temperature)
