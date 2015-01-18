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
      'target_name': 'test',
      'product_name': 'test_sort',
      'type': 'executable',
      'include_dirs': [
        '../src',
      ],
      'sources':
      [
        '../src/test_sort_main.cpp',
      ],
      'link_settings': {
        'libraries': [
        ],
      }
    }
  ]
}