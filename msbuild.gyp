# Copyright (c) 2010 Google Inc. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
    'target_defaults':{
        'msbuild_toolset': 'v143',
        'msvs_configuration_platform': 'x64',
        'msbuild_configuration_attributes':{
            'OutputDirectory': '$(SolutionDir)\\Intermediate\\$(ProjectName)\\$(Configuration)\\',
            'IntermediateDirectory': '$(OutDir)\\Intermediate\\',
            'CharacterSet':'Unicode',
        },
        'configurations': {
            'Debug':{
                'msbuild_settings':{
                    'ClCompile':{
                        'WarningLevel':'Level4',
                        'Optimization':'Disabled',
                        'SDLCheck':'true',

                        'PreprocessorDefinitions':[
                            '_DEBUG',
                            '_WINDOWS',
                            '_ENABLE_EXTENDED_ALIGNED_STORAGE',
                            '_SILENCE_CXX20_CISO646_REMOVED_WARNING',
                            '_SILENCE_ALL_CXX23_DEPRECATION_WARNINGS',
                        ],
                        'ConformanceMode':'true',
                        'MultiProcessorCompilation':'true',
                        'RuntimeLibrary':'MultiThreadedDebug',
                        'LanguageStandard':'stdcpplatest',
                        'DisableSpecificWarnings':[
                            '26451',
                            '26812',
                        ],
                        'AdditionalOptions':[
                            '/Zc:__cplusplus',
                        ],
                    },
                    'Link': {
                        'SubSystem':'Console',
                        'GenerateDebugInformation':'true',
                    },
                },
            },
        },
        'default_configuration': 'Debug',
    },
    
    'targets': [
        {
            'target_name': 'sip_commands',
            'product_name': '$(ProjectName)_$(Configuration)',

            'type': 'executable',
            'include_dirs':[
                './src',
            ],
            'sources':[
                '<!@(cat .sources.lst)',
            ],
            'msbuild_props': [
                '$(SolutionDir)/gyp_tools/sip.props'
            ],
        },
    ],
}