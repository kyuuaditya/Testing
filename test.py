
import math

import os



# Define the initial rotation angles

A, B, C = 0, 0, 0



# Define the width of the cube

cubeWidth = 20



# Define the width and height of the terminal window

width, height = 160, 44



# Initialize the z-buffer and the display buffer

zBuffer = [0] * (width * height)

buffer = [" "] * (width * height)



# Define the ASCII character to use for the background

backgroundASCIICode = "."



# Define the distance from the camera to the cube

distanceFromCam = 100



# Define the horizontal offset of the cube

horizontalOffset = 0



# Define a constant used in the projection calculations

K1 = 40



# Define the speed at which the cube rotates

incrementSpeed = 0.9





def calculateX(i: int, j: int, k: int) -> float:

    """

    Calculate the X coordinate in 3D space.



    Parameters:

        i (int): The X coordinate of the point.

        j (int): The Y coordinate of the point.

        k (int): The Z coordinate of the point.



    Returns:

        float: The calculated X coordinate.

    """

    return (

        j * math.sin(A) * math.sin(B) * math.cos(C)

        - k * math.cos(A) * math.sin(B) * math.cos(C)

        + j * math.cos(A) * math.sin(C)

        + k * math.sin(A) * math.sin(C)

        + i * math.cos(B) * math.cos(C)

    )





def calculateY(i: int, j: int, k: int) -> float:

    """

    Calculate the Y coordinate in 3D space.



    Parameters:

        i (int): The X coordinate of the point.

        j (int): The Y coordinate of the point.

        k (int): The Z coordinate of the point.



    Returns:

        float: The calculated Y coordinate.

    """

    return (

        j * math.cos(A) * math.cos(C)

        + k * math.sin(A) * math.cos(C)

        - j * math.sin(A) * math.sin(B) * math.sin(C)

        + k * math.cos(A) * math.sin(B) * math.sin(C)

        - i * math.cos(B) * math.sin(C)

    )





def calculateZ(i: int, j: int, k: int) -> float:

    """

    Calculate the Z coordinate in 3D space.



    Parameters:

        i (int): The X coordinate of the point.

        j (int): The Y coordinate of the point.

        k (int): The Z coordinate of the point.



    Returns:

        float: The calculated Z coordinate.

    """

    return (

        k * math.cos(A) * math.cos(B) - j * math.sin(A) * math.cos(B) + i * math.sin(B)

    )





def calculateForSurface(cubeX: int, cubeY: int, cubeZ: int, ch: str) -> None:

    """

    Calculate the coordinates for a surface of a cube and update the buffer.



    Parameters:

        cubeX (int): The X coordinate of the cube.

        cubeY (int): The Y coordinate of the cube.

        cubeZ (int): The Z coordinate of the cube.

        ch (str): The character to be displayed at the calculated position.

    """

    global buffer, zBuffer, width, height

    x: float = calculateX(cubeX, cubeY, cubeZ)

    y: float = calculateY(cubeX, cubeY, cubeZ)

    z: float = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam



    ooz: float = 1 / z



    xp = int(width / 2 + horizontalOffset + K1 * ooz * x * 2)

    yp = int(height / 2 + K1 * ooz * y)



    idx: int = xp + yp * width

    if 0 <= idx < width * height and ooz > zBuffer[idx]:

        zBuffer[idx] = ooz

        buffer[idx] = ch





def render() -> None:

    """

    Render the buffer to the console.

    """

    global buffer, zBuffer

    os.system("cls" if os.name == "nt" else "clear")

    for k in range(width * height):

        if k % width:

            print(buffer[k], end="")

        else:

            print()





while True:

    # Initialize the display buffer and the z-buffer

    buffer: list[str] = [" "] * (width * height)

    zBuffer: list[int] = [0] * (width * height)



    # Define the width of the cube and its horizontal offset

    cubeWidth = 20

    horizontalOffset: int = -2 * cubeWidth



    # For each point on the cube's surface, calculate its 2D coordinates and update the display buffer and the z-buffer

    cubeX = -cubeWidth

    while cubeX < cubeWidth:

        cubeY = -cubeWidth

        while cubeY < cubeWidth:

            calculateForSurface(cubeX, cubeY, -cubeWidth, "@")

            calculateForSurface(cubeWidth, cubeY, cubeX, "$")

            calculateForSurface(-cubeWidth, cubeY, -cubeX, "~")

            calculateForSurface(-cubeX, cubeY, cubeWidth, "#")

            calculateForSurface(cubeX, -cubeWidth, -cubeY, ";")

            calculateForSurface(cubeX, cubeWidth, cubeY, "+")

            cubeY += incrementSpeed

        cubeX += incrementSpeed



    # Repeat the above steps for a smaller cube

    cubeWidth = 10

    horizontalOffset = 1 * cubeWidth



    cubeX = -cubeWidth

    while cubeX < cubeWidth:

        cubeY = -cubeWidth

        while cubeY < cubeWidth:

            calculateForSurface(cubeX, cubeY, -cubeWidth, "@")

            calculateForSurface(cubeWidth, cubeY, cubeX, "$")

            calculateForSurface(-cubeWidth, cubeY, -cubeX, "~")

            calculateForSurface(-cubeX, cubeY, cubeWidth, "#")

            calculateForSurface(cubeX, -cubeWidth, -cubeY, ";")

            calculateForSurface(cubeX, cubeWidth, cubeY, "+")

            cubeY += incrementSpeed

        cubeX += incrementSpeed



    # Repeat the above steps for an even smaller cube

    cubeWidth = 5

    horizontalOffset = 8 * cubeWidth



    cubeX = -cubeWidth

    while cubeX < cubeWidth:

        cubeY = -cubeWidth

        while cubeY < cubeWidth:

            calculateForSurface(cubeX, cubeY, -cubeWidth, "@")

            calculateForSurface(cubeWidth, cubeY, cubeX, "$")

            calculateForSurface(-cubeWidth, cubeY, -cubeX, "~")

            calculateForSurface(-cubeX, cubeY, cubeWidth, "#")

            calculateForSurface(cubeX, -cubeWidth, -cubeY, ";")

            calculateForSurface(cubeX, cubeWidth, cubeY, "+")

            cubeY += incrementSpeed

        cubeX += incrementSpeed



    # Render the current state of the display buffer to the terminal

    render()



    # Increment the rotation angles, causing the cubes to rotate

    A += 0.05

    B += 0.05

    C += 0.01
