from google import genai
from google.genai import types
from google.genai.types import HarmCategory, HarmBlockThreshold

safety_settings = [
    {
        "category": HarmCategory.HARM_CATEGORY_HATE_SPEECH,
        "threshold": HarmBlockThreshold.BLOCK_NONE,
    },
    {
        "category": HarmCategory.HARM_CATEGORY_SEXUALLY_EXPLICIT,
        "threshold": HarmBlockThreshold.BLOCK_NONE,
    },
    {
        "category": HarmCategory.HARM_CATEGORY_DANGEROUS_CONTENT,
        "threshold": HarmBlockThreshold.BLOCK_NONE,
    },
    {
        "category": HarmCategory.HARM_CATEGORY_HARASSMENT,
        "threshold": HarmBlockThreshold.BLOCK_NONE,
    },
    {
        "category": HarmCategory.HARM_CATEGORY_CIVIC_INTEGRITY,
        "threshold": HarmBlockThreshold.BLOCK_NONE,
    },
]

client = genai.Client(api_key="AIzaSyD-hSTKdbUDbvi43hlyY3VHHxXbrBoK2-k")

my_file = client.files.upload(file=r"D:\Downloads\raw\zjm\蛙蛙kiyo\2022-03-05 21.18.19-图集-蛙蛙kiyo-#帅哥 快乐每一天_3.jpeg")

response = client.models.generate_content_stream(
    model="gemini-2.5-flash-preview-04-17",
    contents=[
        my_file,
        '描述一下这张图片',
    ],
    config=types.GenerateContentConfig(
        safety_settings=[
            types.SafetySetting(
                category=s["category"],
                threshold=s["threshold"]
            ) for s in safety_settings
        ]
    )
)

for chunk in response:
    print(chunk.text, end="")
