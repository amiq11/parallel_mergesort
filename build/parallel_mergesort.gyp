{
  'includes': [
    'common.gypi',
  ],
  'targets': [
    {
      'target_name': 'main',
      'product_name': 'parallel_mergesort',
      'type': 'executable',
      'include_dirs': [
        '../src',
      ],
      'sources':
      [
        '../src/main.cpp',
      ],
      'link_settings': {
        'libraries': [
        ],
      }
    },
    {
      'target_name': 'sort_unittest',
      'product_name': 'sort_unittest',
      'type': 'executable',
      'include_dirs': [
        '../src',
      ],
      'dependencies': [
        'libgtest',
      ],
      'sources':
      [
        '../src/sort_unittest.cpp',
      ],
      'link_settings': {
        'libraries': [
        ],
      }
    },
    {
      'target_name': 'libgtest',
      'product_name': 'libgtest',
      'type': 'static_library',
      'include_dirs': [
        '../third_party/gtest-1.7.0',
        '../third_party/gtest-1.7.0/include',
      ],
      'sources': [
        '../third_party/gtest-1.7.0/src/gtest-all.cc',
      ],
      'link_settings': {
        'libraries': [
          '-pthread'
        ],
      },
      'direct_dependent_settings': {
        'include_dirs': [
          '../third_party/gtest-1.7.0/include'
        ]
      }
    }
  ]
}