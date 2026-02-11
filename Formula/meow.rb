class Meow < Formula
  desc "Tiny cat-like CLI tool to practice C"
  homepage "https://github.com/tgiachi/meow"
  head "https://github.com/tgiachi/meow.git", branch: "main"

  depends_on "cmake" => :build

  def install
    system "cmake", "-S", ".", "-B", "build", *std_cmake_args
    system "cmake", "--build", "build"
    system "cmake", "--install", "build"
  end

  test do
    (testpath/"sample.txt").write("meow\n")
    assert_equal "meow\n", shell_output("#{bin}/meow #{testpath}/sample.txt")
  end
end
