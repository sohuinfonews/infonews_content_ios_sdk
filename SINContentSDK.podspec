Pod::Spec.new do |s|
s.name                  = 'SINContentSDK'
s.version               = '0.1.3'
s.summary               = '搜狐内容联盟广告sdk'
s.homepage              = 'https://github.com/sohuinfonews/infonews_content_ios_sdk'
s.description           = 'DESC infonews_content_ios_sdk pod.DESC'
s.license               = { :type => 'MIT', :file => 'LICENSE' }
s.author                = { 'wangfei' => 'feiwang216830@sohu-inc.com','xiaoxiao' => 'shawnxiao@sohu-inc.com' }
s.source                = { :git => 'https://github.com/sohuinfonews/infonews_content_ios_sdk.git', :tag => s.version.to_s }
s.platform              = :ios, '9.0'
#s.resource              = 'SINContentFramework/SINContent.bundle'
s.vendored_frameworks   = 'SINContentFramework/SINSSPADFramework.framework', 'SINContentFramework/SINContentFramework.framework'
end