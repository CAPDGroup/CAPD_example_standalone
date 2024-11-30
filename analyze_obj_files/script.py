import subprocess
import re
from typing import List

def find_object_files(root : str) -> List[str]:
    command = f'find {root} -name *.o'

    result = subprocess.run(command, shell=True, capture_output=True, text=True)

    assert result.returncode == 0
    return result.stdout.split('\n')


def run_readelf_cmd(path : str) -> List[str]:
    command = f'readelf -s --wide {path}'
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    assert result.returncode == 0

    return result.stdout.split('\n')


def filter_symbols(symbols : List[str]) -> List[str]:

    assert len(symbols) > 1

    ret = []
    for line in symbols[3:]:
        columns = re.sub('\s+', ' ', line).split(' ')

        if len(columns) == 9:
            if columns[4] == 'FUNC':
                ret.append(columns[8])

    return ret

if __name__ == '__main__':

    paths = find_object_files('.')

    paths = [p for p in paths if p.find('cxsc') == -1 and p.find('filib') == -1]

    total_dict = {}

    paths = [path for path in paths if len(path) > 0 and path.find('main.cpp.o') == -1]
    for path in paths:

        print(path)

        output = run_readelf_cmd(path)
        symbols = filter_symbols(output)
        for symbol in symbols:
            total_dict[symbol] = total_dict.get(symbol, -1) + 1
        
    total_list = list(total_dict.items())
    total_list.sort(key=lambda item : item[1])

    # for item in total_list:
    #    print(f'{item[1]} {item[0]}')

    histogram_dict = {}
    for func in total_list:
        repetitions = func[1]
        histogram_dict[repetitions] = histogram_dict.get(repetitions, 0) + 1
    
    print(histogram_dict)
    print(sum([h[0] * h[1] for h in histogram_dict.items()]))


