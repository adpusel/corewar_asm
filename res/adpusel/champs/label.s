.name           "42"
.comment        "Just a basic Winner Program"

live_1: zjump	%:live_2 01 00 03
live_2: live	%:live_3 01 00 00 00 05
live_3: live	%:live_1 01 ff ff ff f6
