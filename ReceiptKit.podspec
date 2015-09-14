Pod::Spec.new do |s|
  s.name         = 'ReceiptKit'
  s.version      = '1.0.0'
  s.summary      = 'Simple StoreKit receipt validation and processing.'
  s.author       = { 'Richard Stelling' => 'support@empiricalmagic.com' }
  s.source       = { :git => 'https://github.com/rjstelling/ReceiptKit.git' }
  s.source_files = 'src/*.{h,m}'
end
