import cv2
import numpy as np
import matplotlib.pyplot as plt

def scale_image_forward(image, scale_factor):
    original_height, original_width = image.shape[:2]
    new_height, new_width = int(original_height * scale_factor), int(original_width * scale_factor)
    scaled_image = np.zeros((new_height, new_width, image.shape[2]), dtype=np.uint8)

    for y in range(original_height):
        for x in range(original_width):
            new_x, new_y = int(x * scale_factor), int(y * scale_factor)
            scaled_image[new_y, new_x] = image[y, x]

    return scaled_image

def scale_image_inverse(image, scale_factor):
    original_height, original_width = image.shape[:2]
    new_height, new_width = int(original_height * scale_factor), int(original_width * scale_factor)
    scaled_image = np.zeros((new_height, new_width, image.shape[2]), dtype=np.uint8)

    for y in range(new_height):
        for x in range(new_width):
            orig_x, orig_y = int(x / scale_factor), int(y / scale_factor)
            scaled_image[y, x] = image[orig_y, orig_x]

    return scaled_image

# 이미지 파일 경로
image_path = '/Users/minhee/Downloads/test.png'  # 실제 이미지 파일 경로로 변경하세요
image = cv2.imread(image_path)

if image is None:
    print("이미지를 불러오는 데 실패했습니다. 파일 경로를 확인해 주세요.")
else:
    # 이미지 확대
    scaled_image_forward = scale_image_forward(image, 4)
    scaled_image_inverse = scale_image_inverse(image, 4)

    # 결과 출력
    plt.figure(figsize=(15, 5))

    plt.subplot(1, 3, 1)
    plt.title("Original Image")
    plt.imshow(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    plt.axis('off')

    plt.subplot(1, 3, 2)
    plt.title("Forward Mapping")
    plt.imshow(cv2.cvtColor(scaled_image_forward, cv2.COLOR_BGR2RGB))
    plt.axis('off')

    plt.subplot(1, 3, 3)
    plt.title("Inverse Mapping")
    plt.imshow(cv2.cvtColor(scaled_image_inverse, cv2.COLOR_BGR2RGB))
    plt.axis('off')

    plt.show()