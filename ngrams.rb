# An N-gram is a sequence of N consecutive characters from a given word. For the
# word "pilot" there are three 3-grams: "pil", "ilo" and "lot"
# 
# Note that your function will receive the following arguments:
# text: which is a string containing words separated by whitespaces
# ngramLength: which is an integer value giving the length of the n-gram
#
# Data contraints
# The length of the text string will not exceed 200,000 characters
# All words are alphanumeric (they contain only English letters a-z, A-Z and
#	numbers 0-9)
#
# Efficiency contraints
# Your function is expected to print the result in less than 2 seconds
#
# Example.
# Input: text: "aaaab aOa baab c"
# 			 ngramLength: 3
# Output: aaa

def find_ngram(text, ngram_length)
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

