# Aliases for convenient g++ commands for competitive programming
cp_flags="-DCP_DEBUG_ -O2 -Wall -Wextra -Wshadow -fsanitize=undefined -std=c++11"
for x in {a..z}
do
  alias g++$x="g++ $cp_flags -o $x"
done