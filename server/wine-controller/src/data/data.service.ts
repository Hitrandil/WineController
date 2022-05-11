import { Injectable } from '@nestjs/common';
import { LogDto } from './dto';

@Injectable()
export class DataService {
    getESPLog(logEPS: LogDto){
        return logEPS;
    }
}
