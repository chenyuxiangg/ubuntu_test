#include "cyx_convert.h"
#include "cyx_global.h"
#include <Windows.h>
#include <QString>
#include <QDebug>

extern "C"
{
#include <libavutil\opt.h>
#include "libavcodec\avcodec.h"
#include "libavformat\avformat.h"
#include "libswscale\swscale.h"
}
#define __STDC_CONSTANT_MACROS

Cyx_Convert::Cyx_Convert(QObject* parent):QObject(parent)
{
    av_register_all();
}

void Cyx_Convert::on_CheckSource(const QString &filepath)
{
    int len = filepath.size();
    char* url = new char[len+1];
    memcpy(url,filepath.toLocal8Bit().data(),len);
    url[len] = '\0';
    AVFormatContext *ic = avformat_alloc_context();

    if (avformat_open_input(&ic, url, NULL, NULL) < 0) {
        return;
    }

    if (avformat_find_stream_info(ic, NULL) < 0) {
        return;
    }

    //输出视频及音频信息
    /*
    qDebug() << "---------- dumping stream info ----------";
    qDebug() << "input format:" << ic->iformat->name;
    qDebug() << "nb_streams:" << ic->nb_streams;

    int64_t start_time = ic->start_time / AV_TIME_BASE;
    qDebug() << "start_time:" << start_time;

    int64_t duration = ic->duration / AV_TIME_BASE;
    qDebug() << "duration:" << duration;

    int video_stream_idx = av_find_best_stream(ic, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    if (video_stream_idx >= 0) {
        AVStream *video_stream = ic->streams[video_stream_idx];
        qDebug() << "video nb_frames:" << video_stream->nb_frames;
        qDebug() << "video codec_id:" << video_stream->codec->codec_id;
        qDebug() << "video codec_name:" << avcodec_get_name(video_stream->codec->codec_id);
        qDebug() << "video width x height:" << video_stream->codec->width << "x" << video_stream->codec->height;
        qDebug() << "video pix_fmt:" << video_stream->codec->pix_fmt;
        qDebug() << "video bitrate:" << (qint64) video_stream->codec->bit_rate / 1000;
        qDebug() << "video avg_frame_rate:" << video_stream->avg_frame_rate.num/video_stream->avg_frame_rate.den;
    }
    int audio_stream_idx = av_find_best_stream(ic, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
        if (audio_stream_idx >= 0) {
            AVStream *audio_stream = ic->streams[audio_stream_idx];
            LOGD("audio codec_id: %d", audio_stream->codec->codec_id);
            LOGD("audio codec_name: %s", avcodec_get_name(audio_stream->codec->codec_id));
            LOGD("audio sample_rate: %d", audio_stream->codec->sample_rate);
            LOGD("audio channels: %d", audio_stream->codec->channels);
            LOGD("audio sample_fmt: %d", audio_stream->codec->sample_fmt);
            LOGD("audio frame_size: %d", audio_stream->codec->frame_size);
            LOGD("audio nb_frames: %lld", audio_stream->nb_frames);
            LOGD("audio bitrate %lld kb/s", (int64_t) audio_stream->codec->bit_rate / 1000);
        }


    qDebug() << "---------- dumping stream info ----------";
*/
    int frame_width = 0;
    int frame_height = 0;
    const int sys_screenw = GetSystemMetrics(SM_CXSCREEN);
    const int sys_screenh = GetSystemMetrics(SM_CYSCREEN);
    int video_stream_idx = av_find_best_stream(ic, AVMEDIA_TYPE_VIDEO, -1, -1, NULL, 0);
    if (video_stream_idx >= 0) {
        AVStream *video_stream = ic->streams[video_stream_idx];
        frame_width = video_stream->codec->width;
        frame_height = video_stream->codec->height;
    }
    if(frame_width != sys_screenw || frame_height != sys_screenh){
        Convert(filepath);
    }
    else{
        m_outpath = filepath;
    }
    emit Converted(m_outpath);
    avformat_close_input(&ic);
}

void Cyx_Convert::Convert(const QString& filepath)
{
    const int sys_screenw = GetSystemMetrics(SM_CXSCREEN);
    const int sys_screenh = GetSystemMetrics(SM_CYSCREEN);
    int flen = filepath.size();
    int index = filepath.lastIndexOf("/");
    QString prefix = filepath.mid(0,index);
    QString filename = filepath.mid(index+1,flen-index-5);
    index = filepath.lastIndexOf(".");
    QString suffix = filepath.mid(index);
    m_outpath = prefix + "/" + filename + "_new" + suffix;
    QString command = "ffmpeg -i " + filepath + " -strict -2 -s " + QString::number(sys_screenw)
            + "x" + QString::number(sys_screenh)+ " " + m_outpath;

    int clen = command.size();
    WCHAR* pcommand = new WCHAR[clen+1];
    command.toWCharArray(pcommand);
    pcommand[clen] = '\0';
    DoCommand(pcommand);
    //WinExec((LPCSTR)pcommand,SW_HIDE);
    //system(pcommand);

    qDebug() << "complement!";

    delete[] pcommand;
    pcommand = nullptr;
}

void Cyx_Convert::DoCommand(LPWSTR command)
{
    qDebug() << command;
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof STARTUPINFO;
    si.wShowWindow = SW_HIDE;
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    BOOL res = CreateProcess(
    NULL,
    command,
    NULL,
    NULL,
    NULL,
    NORMAL_PRIORITY_CLASS,
    NULL,
    NULL,
    &si,
    &pi);

    if(res)
    {
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    }
}
