from enum import Enum
import re

"""
Utility
"""

"""
Segment Types
"""

class SegmentType(Enum):
    TypeDefinition = 0
    Structure = 1
    Fundamental = 2

def classify_segment( raw: str ) -> SegmentType:
    raw = raw.strip()
    
    if raw.startswith("typedef"):
        return SegmentType.TypeDefinition
    elif raw.startswith("struct"):
        return SegmentType.Structure
    else:
        return SegmentType.Fundamental

"""
Segment Parsers
"""

REGEX_TYPEDEF = re.compile(r"""
                           typedef\s+               # Typedef keyword
                           (?P<exist>(?s:.)+)\s+    # Existent type     
                           (?P<alias>\w+);
                           """, flags=re.VERBOSE)

def parse_typedef( raw: str ):
    matches = REGEX_TYPEDEF.match(raw)
    print(matches.group('exist'))
    print(matches.group('alias'))

"""
Test code
"""

if __name__ == "__main__":
    from pathlib import Path

    sample_file = Path(__file__).parent.parent / 'data/single_sample.c'
    with open(sample_file, 'r') as infile:
        sample = ''.join(infile.readlines())
    parse_typedef( sample )