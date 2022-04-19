import gravedad
import gravedadCy
from gravedadCy import step_time
import time
#Initialized planet for python

earth = gravedad.Planet()
earth.x=100e3
earth.y=300e3
earth.z=300e3
earth.vx=2e3
earth.vy=29.87e3
earth.vz=0.034e3
earth.m=5.9736e24

time_span=600
n_steps=4000000
initTime=time.time()
gravedad.step_time(planet=earth,time_span=time_span,n_steps=n_steps)
endTime=time.time()
totalTime = endTime-initTime
print("Tiempo en python",totalTime,"s")

earth = gravedadCy.Planet()
earth.x=100e3
earth.y=300e3
earth.z=300e3
earth.vx=2e3
earth.vy=29.87e3
earth.vz=0.034e3
earth.m=5.9736e24
initTimeCy=time.time()
step_time(planet=earth,time_span=time_span,n_steps=n_steps)
endTimeCy=time.time()
totalTimeCy = endTimeCy-initTimeCy
print("Tiempo en cython",totalTimeCy,"s")

speedUp=totalTime/totalTimeCy
print("SpeedUp",speedUp)