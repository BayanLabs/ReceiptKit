Pod::Spec.new do |spec|
  spec.name                = 'ReceiptKit'
  spec.version             = '1.0.0'
  spec.summary             = 'Simple StoreKit receipt validation and processing.'
  spec.author              = { 'Richard Stelling' => 'support@empiricalmagic.com' }
  spec.homepage            = 'https://github.com/rjstelling/ReceiptKit'
  spec.license             = { :type => 'Custom', :file => 'software-licence-agreement/LICENSE.md' }
  spec.source              = { :git => 'https://github.com/BayanLabs/ReceiptKit.git' }
  spec.source_files        = 'src/*.{h,m}', 'open-ssl/include/*/*.h'
  spec.header_dir          = 'openssl'
  spec.header_mappings_dir = 'open-ssl/include/openssl'
  spec.xcconfig            = { 'HEADER_SEARCH_PATHS' => '"$(PODS_ROOT)/ReceiptKit/src/"' }
end
