
std::vector<cv::String> fn;

/*

void cv::glob(String pattern, std::vector< String > & result, bool recursive = false )	

*/

cv::glob("/home/images/*.png", fn, false);
// or 
cv::glob(dataPath + "/*.jpg", fn, false);

int count = fn.size(); 
for (int i=0; i<count; i++)
{
    std::cout << fn[i] << std::endl; 
    cv::Mat frame = imread(fn[i]);
    ...
}