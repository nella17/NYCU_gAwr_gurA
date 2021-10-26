cp -r `dirname $(dirname $(g++ df.cpp -H 2>&1 | head -n 1 | awk '{ print $2 }'))` ~/include
g++ -std=c++17 stdc++.h -I$HOME/include
