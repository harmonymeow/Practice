def find_ngram(text, ngram_length)
	# Write your code here
	# To print results to the standard output you can use puts
	# Example puts "Hello world!"
	pos = 0
	frequency = Hash.new(0)
	while pos < text.length - ngram_length
		temp = text.slice(pos..pos+ngram_length-1)
		frequency[:"#{temp}"] += 1
		pos += 1
	end
	output_key = " "
	output_value = 0
	frequency.each do |key, value|
		if value > output_value
			output_value = value
			output_key = key
		end
	end
	puts output_key
end

