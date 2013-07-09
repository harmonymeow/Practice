RIGHT = 1
DOWN = 4
LEFT = -1
UP = -4

def roll_snake(matrix, width)
    # Write your code here
    # To print results to the standard output you can use puts
    # Example puts "Hello world!"

    visited = Array.new

    direction = RIGHT
    pos = 0
    count = 0

    while true
    	turned = false
    	visited << matrix[pos]
    	
    	if (count >= width -1 || 
    				visited.include?(matrix[pos+direction])) && 
    				direction == RIGHT
    		count = 0
    		direction = DOWN
    		turned = true
    	end
    	if (count >= width -1 || 
    				visited.include?(matrix[pos+direction])) && 
    				direction == DOWN
    		count = 0
    		direction = LEFT
    		turned = true
    	end
    	if (count >= width || 
    				visited.include?(matrix[pos+direction])) && 
    				direction == LEFT
    		count = 0
    		direction = UP
    		turned = true
    	end
    	if (count >= width || 
    				visited.include?(matrix[pos+direction])) && 
    				direction == UP
    		count = 0
    		direction = RIGHT
    		turned = true
    	end
    	if turned = true && visited.include?(matrix[pos+direction])
    		break
    	end
    	count += 1
    	pos += direction
    end
    print visited.join(" ")
end

roll_snake([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16], 4)