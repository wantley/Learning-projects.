extends KinematicBody2D 

var distance = 1
var speed = 500
var move = ["up", "down", "left","rigth"]
const timeLimit = 0.5
var time = 0

func _ready():
	pass # Replace with function body.
func _physics_process(delta):
	time += delta
	if time >= timeLimit:
		var motion = Vector2()
		var choice = move[randi() % move.size()]
		if choice == "up":
			motion.y -= distance
		if choice == "down":
			motion.y += distance
		if choice == "right":
			motion.x += distance
		if choice == "left":	
			motion.x -=	distance
		move_and_slide(speed*motion)
		time = 0
	



# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
