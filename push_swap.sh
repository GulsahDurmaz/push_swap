#!/bin/bash
# Prompt the user for a file path
# echo "Please enter the path to your push_swap executable:"
# read executablePath
# echo "Please enter the path to your checker_OS executable:"
# read checkerPath
executablePath="./push_swap"
checkerPath="./checker"
# random ints
hun_random="-51 237 -177 -88 -68 204 283 251 85 179 160 -119 -145
-228 15 -217 224 300 -58 254 76 -107 -256 -210 -92 -157 -90 -185
-257 161 172 148 -108 -212 264 -86 200 189 -272 175 -103 140 156
207 -290 -130 43 -57 -251 -183 164 124 -226 106 -140 133 -215 -159
-201 -114 291 -173 6 -111 -291 -102 104 -237 -254 66 -128 27 130 78
218 13 50 60 -240 -46 183 214 -116 138 -105 22 52 -7 30 -271 -259 -16
158 245 -65 -172 -129 -156 206 190"
five_hun_random="-273 -78 -206 200 267 173 -119 -278 -204 -3 -187 -6
-214 -130 251 -157 294 -107 -209 -57 250 -176 -32 -224 -289 -280 72
273 -129 258 218 237 192 16 80 -188 236 -197 280 111 -1 -223 106 -263
-69 263 -38 223 -230 233 -76 167 -62 -40 264 300 -46 -12 -60 162 63 256
-169 55 129 131 253 -185 188 -208 19 -139 282 -33 -167 -103 -210 -244 134
61 -151 -173 94 196 -135 -104 -20 23 11 163 92 274 -260 209 -96 -106 20 110
-11 -189 292 40 177 -207 285 125 124 191 -94 -171 229 -293 259 -4 206 126 -56
186 -35 -121 8 -174 154 268 214 149 -282 -245 -213 -26 3 105 48 2 -283 -84 299
-72 -113 -227 -17 -299 -236 -13 -44 -172 -266 208 239 -250 -70 210 88 -202 -163
171 42 234 -239 -272 -142 -238 96 -267 78 32 262 -112 -195 -99 -234 36 189 90 142
179 56 -229 169 79 -192 -75 -291 -257 -66 240 121 -217 128 165 246 120 -90 -240 47
-256 98 -9 166 -123 159 15 -93 -181 172 150 -137 295 10 152 75 74 -85 -255 -226 -71
-156 -125 175 9 118 -162 221 266 82 -159 -120 -127 26 -284 86 -268 -153 -186 -7 203
-49 -29 -149 -254 43 68 66 -198 276 -81 -45 109 119 202 58 -297 -50 -118 217 195 245
97 -147 85 -105 -201 70 215 -37 -63 -82 -43 112 -292 -247 158 -275 137 -205 113 -178
-36 -18 91 193 -203 -133 18 4 247 73 -161 31 -175 -132 136 -100 249 254 -111 102
-110 143 -109 155 133 52 27 -246 -276 54 -80 238 114 -146 28 -55 269 -251 -79 -265
227 182 183 212 -108 -64 -177 278 -279 -154 -222 -164 107 194 -92 -28 -215 160 255
-288 181 135 122 50 -23 -115 -52 199 -165 190 242 -86 -264 -269 64 -24 -77 -131 291
-51 198 176 180 185 -144 -199 0 -295 -30 197 -155 -138 104 117 284 -160 -95 293 -150
248 286 156 213 281 -22 14 -194 -259 -68 -15 -235 100 141 -184 5 222 -74 59 115 216
205 -126 -248 -124 -42 37 270 243 30 -54 168 29 298 164 -232 -16 228 17 290 132 -237
-221 225 297 6 -27 -59 260 -73 71 -182 84 -145 145 -258 -261 -143 138 -140 -158 -31
-190 -180 -134 201 231 57 184 116 -91 -253 -166 127 38 139 123 49 241 89 21 -48 103
-219 -14 157 -152 39 -200 -19 -25 62 252 -274 -101 99 -193 -183 -102 24 288 77 147 1
13 -285 219 -242 -8 81 151 161 -211 -290 -300 -87 12 130 -216 83 -65 53 144 -34"
# valgrind --leak-check=full $executablePath 2>&1 | grep -E \"definitely lost\|indirectly lost|All heap blocks\""
# List of commands to execute
commands=(
"$executablePath a2 39a W"
"$executablePath 1 2 2 4 3"
"$executablePath 1 2 4 2147483648"
"$executablePath"
"$executablePath 42"
"$executablePath 2 3"
"$executablePath 0 1 2 3"
"$executablePath 0 1 2 3 4 5 6 7 8 9"
"$executablePath 0 1 3 6 7 8 9"
"ARG=\"2 1 0\"; $executablePath \$ARG | $checkerPath \$ARG; $executablePath \$ARG | wc -l"
"ARG=\"2 88 -10\"; $executablePath \$ARG | $checkerPath \$ARG; $executablePath \$ARG | wc -l"
"ARG=\"1 5 2 4 3\"; $executablePath \$ARG | $checkerPath \$ARG; $executablePath \$ARG | wc -l"
"ARG=\"99 1 293 -1 2\"; $executablePath \$ARG | $checkerPath \$ARG; $executablePath \$ARG | wc -l"
"ARG=\"$hun_random\"; $executablePath \$ARG | $checkerPath \$ARG; $executablePath \$ARG | wc -l"
"ARG=\"$five_hun_random\"; $executablePath \$ARG | $checkerPath \$ARG; $executablePath \$ARG | wc -l"
)
# Iterate over the commands
for command in "${commands[@]}"; do
  clear
  # Display the command to be executed
  echo "Executing command: $command"
  # Execute the command and display its output
  echo "--------------------------------------"
  eval "$command"
  echo "--------------------------------------"
  # Prompt the user to continue
  read -p "Press Enter to continue to the next command..."
done
#clear
