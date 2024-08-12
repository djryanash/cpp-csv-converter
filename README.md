# Simple C++ script for propogating values to successive columns of a .CSV file when the column is empty.

FROM THIS...
| :---: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :---: |
| Apple | Bananas |         |         |         | Carrots |         |         | Dates |


TO THIS...
| :---: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :-----: | :---: |
| Apple | Bananas | Bananas | Bananas | Bananas | Carrots | Carrots | Carrots | Dates |

