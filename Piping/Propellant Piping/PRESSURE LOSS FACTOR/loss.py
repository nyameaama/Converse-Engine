from constants import *

def LOX_fluid_viscosity():
    #Determine laminar or turbulent flow by reynolds number

    #The Reynolds number (Re) of a flowing fluid
    #is calculated by multiplying the fluid velocity by
    #the internal pipe diameter (to obtain the inertia force 
    #of the fluid) and then dividing the result by the kinematic viscosity
    #(viscous force per unit length). 
    #Kinematic viscosity = dynamic viscosity/fluid density 
    #Reynolds number = (Fluid velocity x Internal pipe diameter) / Kinematic viscosity
    dynamic_viscosity = 0
    kinematic_V = dynamic_viscosity / LOX_density 
    reynolds_num = (LOX_Fluid_velocity * LOX_Internal_pipe_diameter) / kinematic_V

    #Calculate friction factor
    