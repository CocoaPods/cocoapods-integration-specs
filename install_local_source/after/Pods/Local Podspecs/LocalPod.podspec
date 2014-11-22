Pod::Spec.new do |s|
  s.name    = "LocalPod"
  s.version = "1.0"
  s.source  = { :http => "./LocalPod.zip" }

  s.subspec "subspec_1" do |ss|
    ss.source_files = "subspec_1/**/*.{h,m}"
    ss.resource_bundles = {
      "SubSpec_1" => ["subspec_1/**/*.png"]
    }
  end

  s.subspec "subspec_2" do |ss|
    ss.source_files = "subspec_2/**/*.{h,m}"
    ss.resource_bundles = {
      "SubSpec_2" => ["subspec_2/**/*.png"]
    }
  end
end
