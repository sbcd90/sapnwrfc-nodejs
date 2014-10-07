sapnwrfc-nodejs
===============

This is a demo repo for testing connection to a SAP System from node.js using SAPNWRFC SDK.


Test
====

- create a small function module in SAP ABAP System

                            FUNCTION ZTESTNEWFM.
                            *"----------------------------------------------------------------------
                            *"*"Local Interface:
                            *"  IMPORTING
                            *"     VALUE(ZINP) TYPE  INT4
                            *"  EXPORTING
                            *"     VALUE(ZEXP) TYPE  INT4
                            *"----------------------------------------------------------------------


                              zexp = zinp * zinp.
                            ENDFUNCTION. 
                            
- download SAP NWRFCSDK library from [SAP Service Marketplace](https://websmp103.sap-ag.de/~SAPIDP/002006825000000234912001E)
- extract it.
- download this repo & run "npm install".
