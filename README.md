# mruby-bam   [![build](https://github.com/kojix2/mruby-bam/actions/workflows/ci.yml/badge.svg)](https://github.com/kojix2/mruby-bam/actions/workflows/ci.yml)
Bam class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'kojix2/mruby-bam'
end
```
## example
```ruby
p Bam.hi
#=> "hi!!"
t = Bam.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
