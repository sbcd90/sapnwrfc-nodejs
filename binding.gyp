{
  'variables': {
    'module_name': 'gateway',
    'library': 'shared_library',
    'target_arch': 'x64',
    'output_directory': 'Release',
    'msvs_nwrfcsdk_path': 'C:/Users/i076326/Documents/programs/sapnwrfc-nodejs/nwrfcsdk', #Assumed to be nwrfcsdk
    'OS': 'win'    
  },

  'targets': [{
    'sources': [
      'src/gateway.cc'
    ],
    
    'target_name': 'gateway',
    'type': '<(library)',
    'product_name': '<(module_name)',
    'product_extension': 'node',
    'product_prefix': '',
    
    'defines': [
      'ARCH="<(target_arch)"',
      'PLATFORM="<(OS)"',
      '_LARGEFILE_SOURCE',
      '_FILE_OFFSET_BITS=64',
      'SAPwithUNICODE',
      'SAPwithTHREADS',
      'NDEBUG',
    ],
    
    'conditions': [
      [ 'OS=="win"', {
        'defines': [
          'PLATFORM="win32"',
          'WIN32',
          '_AFXDLL',
          '_CRT_NON_CONFORMING_SWPRINTFS',
          '_CRT_SECURE_NO_DEPRECATE',
          '_CRT_NONSTDC_NO_DEPRECATE',
          'SAPonNT',
          'UNICODE',
          '_UNICODE'
        ],
        'conditions': [
          [ 'target_arch=="ia32"' , {
            'defines' : ['_X86_']
           }],
          [ 'target_arch=="x64"' , {
	           'defines': ['_AMD64_']
           }]
        ],
        'include_dirs': [
          '<(msvs_nwrfcsdk_path)/include'
        ],
        'msvs_settings': {
          'VCLinkerTool': {
            'AdditionalLibraryDirectories': [ '<(msvs_nwrfcsdk_path)/lib' ],
            'AdditionalDependencies': [ '<(msvs_nwrfcsdk_path)/lib/sapnwrfc.lib', '<(msvs_nwrfcsdk_path)/lib/libsapucum.lib' ]
          },
        },
       'product_dir': '<(output_directory)'
      }
    ],
                ]
        }]
}