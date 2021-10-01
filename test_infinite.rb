require "open3"

PATH = "./"

if ARGV.length != 2 && ARGV.length != 3
	puts "wrong number of arguments, need 2 or 3: length of input, max amount of operations and max amount of tests (optional)"
	exit
end

system("make -C #{PATH}", [:out, :err ] => File::NULL)
if $?.exitstatus != 0
	puts "make failed"
	exit
end


if !File.file?("#{PATH}push_swap")
	puts "executable not found, check path or executable name"
	exit
end

puts "Testing...\nDo note that for execution speed purposes this script doesn't check output correctness, only length"

input_length = ARGV[0].to_i
max = ARGV[1].to_i
max_amount = (ARGV.length == 3 ? ARGV[2].to_i : -1)
slowest_input = ""
count = 0
amount = 0
while count <= max && (max_amount == -1 || amount < max_amount) do
	arg = (0...input_length).to_a.shuffle.join(' ')
	out = `./#{PATH}push_swap #{arg}`
	count = out.split("\n", -1).length
	count -= 1 if count != 0 #because of last \n
	if count > max
		slowest_input = arg
	end
	amount += 1
end

if slowest_input.empty?
	puts "Never crossed the max, bravo!"
else
	puts "input:\n%s\namount of operations: %d\n" % [slowest_input, count]
end
