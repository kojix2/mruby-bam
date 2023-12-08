##
## Bam Test
##

assert("Bam#hello") do
  t = Bam.new "hello"
  assert_equal("hello", t.hello)
end

assert("Bam#bye") do
  t = Bam.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Bam.hi") do
  assert_equal("hi!!", Bam.hi)
end
