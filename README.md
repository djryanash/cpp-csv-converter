# Simple C++ script for propogating values to successive columns of a .CSV file when the column is empty.



For example:

THIS...

Global Markets,FX&EM,FX G10,,,Total Expesnes,Direct Costs,NPE,Trade NPE,,,73410.55821

Investment Banking,ECM,,,,Total Expesnes,Direct Costs,Other Directs,,,,419513.8194

Investment Banking,Advisory,Industry,Financial Institutions,,Total Expesnes,Indirect Costs,Corporate Allocation,EMEA,CIO,Group Operations,287699.0829





BECOMES THIS...

Global Markets,FX&EM,FX G10,FX G10,FX G10,Total Expesnes,Direct Costs,NPE,Trade NPE,Trade NPE,Trade NPE,73410.55821

Investment Banking,ECM,ECM,ECM,ECM,Total Expesnes,Direct Costs,Other Directs,Other Directs,Other Directs,Other Directs,419513.8194

Investment Banking,Advisory,Industry,Financial Institutions,Financial Institutions,Total Expesnes,Indirect Costs,Corporate Allocation,EMEA,CIO,Group Operations,287699.0829


