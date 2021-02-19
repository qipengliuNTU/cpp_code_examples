

// need to set mask file path
std::ifstream mask_file(mask_path);

// store each line of mask file
std::string line;
std::vector<cv::String> mask_list;
if (mask_file.is_open())
{
    while (getline(mask_file, line))
    {
        mask_list.push_back(line);
    }
    mask_file.close();
}
else
    std::cout << "Unable to open file for reading";

// each image has its own mask
for (int img_i = 0; img_i < count; img_i += 2)
{
    std::cout << fn[img_i] << std::endl;
    cv::Mat img = cv::imread(fn[img_i]);
    if (img.empty())
    {
        std::cerr << std::endl
                  << "Failed to load: " << fn[img_i] << std::endl;
        exit(1);
    }

    // set mask for this img
    cv::Mat mask(img.size(), CV_8U, cv::Scalar(255));
    std::istringstream mask_single_line(mask_list[img_i]);
    std::vector<std::string> mask_single_list;
    std::string single;
    while (getline(mask_single_line, single, ' '))
    {
        mask_single_list.push_back(single);
    }
    for (int i = 0; i < mask_single_list.size(); i += 4)
    {
        int x1 = stoi(std::string(mask_single_list[i]));
        int y1 = stoi(std::string(mask_single_list[i + 1]));
        int x2 = stoi(std::string(mask_single_list[i + 2]));
        int y2 = stoi(std::string(mask_single_list[i + 3]));
        mask(cv::Rect(cv::Point(x1, y1), cv::Point(x2, y2))) = 0;
    }
    surf_detector->detectAndCompute(img, mask, keys, descs); // without mask ---> cv::Mat()

    cv::Mat img_keys;
    cv::drawKeypoints(img, keys, img_keys); // outputImage = img_keys
    cv::imshow("Keypoints", img_keys);
    cv::waitKey();
}
