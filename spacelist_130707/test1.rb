def roll_snake(matrix, width)
    # Write your code here
    # To print results to the standard output you can use puts
    # Example puts "Hello world!"

    new_matrix = Array.new(width) { Array.new(width)}
    x = 0
    y = 0
    pos = 0
    matrix.each do |a|
    	new_matrix[x][y] = a
  		x += 1
  		if x >= width -1
  			y += 1
  			x = 0
  		end
  	end
  	print new_matrix
end

roll_snake([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16], 4)