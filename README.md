# Following-20

 Following'20 is an annual flagship event(inter college competition), exclusively for 1st years conducted by the RMI(Robotics and Machine Intelligence) club of NIT-Trichy.
this took place during August 2020.

## Theme:

Rick while testing one of his latest inventions accidently shoots Summer off to another dimension. Seeing this, Morty, being Morty, panics and goes dimension hopping with Rick to rescue his sister before their parents come back home. As the duo arrive at each dimension, they encounter odd shapes left out by the dimension travelling Summer, as clues to her location. They must decode these clues and arrive at the correct dimension. However, they must defeat the pursuing Galactic Federation Troops in order to continue their travel. Now try building a robot which could help Rick and Morty through their new mission.

## Arena Description and Layout:

The arena consists of black lines arranged in a grid. A sample track is shown below. The points of intersection are known as nodes. All the nodes will have distinct 2D cartesian coordinates in the grid. Additionally, there will be a start node as shown in the sample arena. The arena consists of 25 nodes and a start node at (0, 0). Each node has a specific coordinate, denoted by X and Y axes. The numbering of the X and Y axes are shown in the figure. The thickness of all the lines is 3 cm. The distance between the nodes will be at least 30 cm.

# Phases of the problem statement:

## Phase 1:

At the beginning of the task, the bot will be placed at the start node. The goal of Phase 1 is to make the bot move to any given node, with coordinates (X, Y). The coordinates of the target node can be sent to the bot via any wireless means. The bot must travel to the target node, wait for 1 second and then come back to the starting point.

## Phase 2:

The bot will start from the start node. Shapes printed on an A4 sheet will be shown to the laptop camera. Your task is to read and decode the X and Y coordinates of the target node from the shapes (For more details, refer Image Processing Guidelines in the problem statement pdf attached). The bot then has to move to the decoded target node and wait there until another set of shapes is shown. This will specify the next target node.
This process will be repeated two more times with different shapes. Shapes corresponding to the Start Node will be shown at the end, which implies that the bot must return to the starting node.

## Phase 3:

Similar to Phase 2 printed out shapes are shown to the laptop camera to decode coordinates. After finding the coordinates while the bot travels to the target node obstacles would be randomly places by organisers on the track. The bot should be able to detect the obstacle present on the track and reroute its path to reach the target node. Negative points will be awarded if the bot doesn’t identify the obstacle and touches it.
This process will be repeated two more times with different shapes. Shapes corresponding to the Start Node will be shown at the end, which implies that the bot must return to the starting node.

## NOTE:

In case the bot moves to a point which does not match the image processing result, the bot will be reset to the correct node by the organiser, before the next set of shapes is shown to the laptop. (e.g: If the IP detects (2,3) and the bot moves to any other point, then the organiser will reset the bot to (2,3))
