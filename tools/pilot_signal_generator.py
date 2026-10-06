#!/usr/bin/env python3
"""Print deterministic pilot test vectors for firmware validation."""

def vector(period_us:int,high_us:int):
    frequency=1_000_000/period_us
    duty=100*high_us/period_us
    print(f"period={period_us}us high={high_us}us frequency={frequency:.1f}Hz duty={duty:.1f}%")

for item in [(1000,500),(1000,100),(1000,900),(1200,600),(800,400)]:
    vector(*item)
